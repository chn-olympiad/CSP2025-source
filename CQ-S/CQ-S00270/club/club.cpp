#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int t,n,len[3],num;
struct l{
	int a,b,c;
}s[MAXN],ns[MAXN][3],ts[MAXN];
bool cmp(l a,l b){
	return a.a-a.b<b.a-b.b;
}
void cal(int lx){
	for(int i=1;i<=len[lx];i++){
		ts[i]=ns[i][lx];
	}
	int nedj=len[lx]-n/2;
	sort(ts+1,ts+len[lx]+1,cmp);
	for(int i=1;i<=nedj;i++){
		num-=ts[i].a-ts[i].b;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		len[0]=len[1]=len[2]=0;
		num=0;
		for(int i=1;i<=n;i++){
			int a,b,c,d[4];
			l lt;
			cin>>a>>b>>c;
			d[0]=a;
			d[1]=b;
			d[2]=c;
			sort(d,d+3);
			lt={d[2],d[1],d[0]};
			num+=d[2];
			if(a>b&&a>c){
				ns[++len[0]][0]=lt;
			}
			if(b>a&&b>c){
				ns[++len[1]][1]=lt;
			}
			if(c>b&&c>a){
				ns[++len[2]][2]=lt;
			}
		}
		for(int i=0;i<=2;i++){
			if(len[i]>n/2){
				cal(i);
			}
		}
		cout<<num<<'\n';
	}
	return 0;
}
