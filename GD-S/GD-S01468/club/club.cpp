#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,b[5],ans,c[N],tot;
struct node{int a,id;}a[N][5];
bool cmp(node x,node y){
	if(x.a!=y.a)return x.a>y.a;
	return x.id<y.id;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n,b[0]=b[1]=b[2]=ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0].a>>a[i][1].a>>a[i][2].a;
			for(int j=0;j<3;j++)a[i][j].id=j;
			sort(a[i],a[i]+3,cmp);
			ans+=a[i][0].a,b[a[i][0].id]++;
		}
		int mx=0;
		if(b[1]>b[mx])mx=1;
		if(b[2]>b[mx])mx=2;
		if(b[mx]>n/2){
			tot=0;
			for(int i=1;i<=n;i++){
				if(a[i][0].id==mx)c[++tot]=a[i][0].a-a[i][1].a;
			}
			sort(c+1,c+1+tot);
			for(int i=n/2+1;i<=b[mx];i++)ans-=c[i-n/2];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
