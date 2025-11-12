#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+15;
int t,n,f[N/2];
struct node{
	int a,b,c;
	void input(){cin>>a>>b>>c;}
}abc[N];
bool cmp(node x,node y){
	return x.a-x.b>y.a-y.b;
}
bool cmp2(node x,node y){
	return x.a>x.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		bool flag1=true,flag2=true;
		for(int i=1;i<=n;i++){
			abc[i].input();
			if(abc[i].b!=0) flag1=false;
			if(abc[i].c!=0) flag2=false;
		}
		sort(abc+1,abc+n+1,cmp);
		if(flag1&&flag2){
			sort(abc+1,abc+n+1,cmp2);
			int ans=0;
			for(int i=1;i<=n/2;i++) ans+=abc[i].a;
			cout<<ans<<endl;
		}else if(flag2){
			int ans=0;
			for(int i=1;i<=n/2;i++) ans+=abc[i].a,ans+=abc[i+n/2].b;
			cout<<ans<<endl;
		}
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			for(int j=min(i,n/2);j>=0;j--){
				if(i-j>0&&i-j<=n/2) f[j]=f[j]+abc[i].a;
				else f[j]=f[j]+abc[i].b;
				if(j) f[j]=max(f[j],f[j-1]+abc[i].c);
			}
		}
		int ans=0;
		for(int j=0;j<=n/2;j++){
			ans=max(ans,f[j]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
