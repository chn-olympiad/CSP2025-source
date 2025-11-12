#\
i\
n\
c\
l\
u\
d\
e\
<\
b\
i\
t\
s\
/\
s\
t\
d\
c\
+\
+\
.\
h\
>
#\
d\
e\
f\
i\
n\
e\
 \
a\
k\
i\
o\
i\
 \
r\
e\
t\
u\
r\
n\
 \
0
#define int long long
using namespace std;

struct line{
	int fr,to,len;
}r[11000001];
int n,m,k,ans,c[11],a[11][10001],fa[10001],mp[1001][1001];
bool vis[11];
bool cmp(line x,line y){
	return x.len<y.len;
}
int find(int a){
	if(fa[a]==a)return fa[a];
	fa[a]=find(fa[a]);
	return fa[a];
}
void comb(int a,int b){
	if(find(a)==find(b))return;
	fa[find(a)]=find(b);
}
void kru(){
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(r+1,r+m+1,cmp);
	int ccnntt=0;
	for(int i=1;i<=m;i++){
		if(find(r[i].fr)==find(r[i].to))continue;
		ans+=r[i].len;
		comb(r[i].fr,r[i].to);
		ccnntt++;
		if(ccnntt==n-1)break;
	}
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	freopen("road3.in","r",stdin);
//	freopen("road3.out","w",stdout);
	cin>>n>>m>>k;
	if(n<=1000)memset(mp,0x3f,sizeof(mp));
	for(int i=1;i<=m;i++){
		cin>>r[i].fr>>r[i].to>>r[i].len;
		if(n<=1000)mp[r[i].fr][r[i].to]=min(mp[r[i].fr][r[i].to],r[i].len);
	}
	bool fg=true;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)fg=false;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0){
		kru();
		cout<<ans;
		akioi;
	}
	if(fg==true&&n<=1000){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int l=1;l<=k;l++){
					int len=a[l][i]+a[l][j];
					if(len<mp[i][j]&&len<mp[j][i]){
						mp[i][j]=mp[j][i]=len;
						r[++m].fr=i;
						r[m].to=j;
						r[m].len=len;
					}
				}
			}
		}
		kru();
		cout<<ans;
		akioi;
	}
	akioi;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4


4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
