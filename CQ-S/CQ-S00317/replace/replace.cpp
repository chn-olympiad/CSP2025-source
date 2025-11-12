#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5,M=5e6+5;
int n,q,sum,l[N],r[N],len[N],ans[N],tree[M];
string s1[N],s2[N];
vector<int> del;
struct node{
	int f,x,y,id;
}t[N*2];
bool cmp(node x,node y){
	if(x.f!=y.f)return x.f<y.f;
	if(x.x!=y.x)return x.x<y.x;
	if(x.y!=y.y)return x.y<y.y;
	return x.id<y.id;
}
#define low(x) (x&-x)
void add(int x,int v){
	if(v>0)del.push_back(x);
	for(int i=x;i<=5e6;i+=low(i)){
		tree[i]+=v;
	}
}
int ask(int x){
	int s=0;
	for(int i=x;i;i-=low(i))s+=tree[i];
	return s;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		len[i]=s1[i].size();
		sum+=len[i];
		l[i]=1;
		for(int j=0;j<len[i];j++){
			if(s1[i][j]!=s2[i][j]){
				l[i]=j;
				break;
			}
		}
		for(int j=len[i]-1;j>=0;j--){
			if(s1[i][j]!=s2[i][j]){
				r[i]=j;
				break;
			}
		}
		if(s1[i][l[i]]=='b')t[i]={r[i]-l[i]+1,l[i]+1,len[i]-r[i],0};
		else t[i]={r[i]-l[i]+1+(int)5e6,l[i]+1,len[i]-r[i],0};
		// printf("%d %d\n",l[i],r[i]);
	}
	if(sum*1ll*q>1e8){
		for(int i=1;i<=q;i++){
			string t1,t2;
			cin>>t1>>t2;
			int m=t1.size(),x=1,y=0;
			for(int j=0;j<m;j++){
				if(t1[j]!=t2[j]){
					x=j;
					break;
				}
			}
			for(int j=m-1;j>=0;j--){
				if(t1[j]!=t2[j]){
					y=j;
					break;
				}
			}
			if(t1[x]=='b')t[n+i]={y-x+1,x+1,m-y,i};
			else t[n+i]={y-x+1+(int)5e6,x+1,m-y,i};
		}
		sort(t+1,t+n+q+1,cmp);
		for(int i=1;i<=n+q;i++){
			if(t[i].f!=t[i-1].f){
				for(int j:del)add(j,-1);
				del.clear();
			}
			if(!t[i].id)add(t[i].y,1);
			else ans[t[i].id]=ask(t[i].y);
		}
		for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
		return 0;
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int m=t1.size(),x=1,y=0;
		for(int j=0;j<m;j++){
			if(t1[j]!=t2[j]){
				x=j;
				break;
			}
		}
		for(int j=m-1;j>=0;j--){
			if(t1[j]!=t2[j]){
				y=j;
				break;
			}
		}
		// printf("%d %d\n",x,y);
		int ans=0;
		for(int i=1;i<=n;i++){
			if(r[i]-l[i]==y-x&&x>=l[i]&&m-y>=len[i]-r[i]){
				int d=x-l[i],flag=0;
				for(int j=0;j<len[i];j++){
					if(s1[i][j]!=t1[j+d]||s2[i][j]!=t2[j+d]){
						flag=1;
						break;
					}
				}
				if(!flag)ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}