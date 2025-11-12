#include<bits/stdc++.h>
using namespace std;
int t,n;
struct edge{
	int a1,a2,a3;
}a[110000];
bool cmp1(edge x,edge y){
	return x.a1>y.a1;
}
bool cmp2(edge x,edge y){
	return rand()%2&&x.a1>y.a1;
}
bool cmp3(edge x,edge y){
	return x.a3>y.a3;
}
int maxx=0;
void dfs(int xx1,int xx2,int xx3,int sum,int i){
	if(xx1>n/2)return;
	if(xx2>n/2)return;
	if(xx3>n/2)return;
	cout<<xx1<<" "<<xx2<<" "<<xx3<<"\n";
	if(xx1+xx2+xx3==n){
		maxx=max(maxx,sum);
		return;
	}
	dfs(xx1+1,xx2,xx3,sum+a[i].a1,i+1);
	dfs(xx1,xx2+1,xx3,sum+a[i].a2,i+1);
	dfs(xx1,xx2,xx3+1,sum+a[i].a3,i+1);
}
int dp[110000][2];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==2){
			int a1=0,a2=0,a3=0,b1=0,b2=0,b3=0;
			cin>>a1>>a2>>a3>>b1>>b2>>b3;
			cout<<max({a1+b2,a1+b3,a2+b1,a2+b3,a3+b1,a3+b2})<<"\n";
		}else if(n==4){
			int a1=0,a2=0,a3=0,b1=0,b2=0,b3=0;
			int c1=0,c2=0,c3=0,d1=0,d2=0,d3=0;
			cin>>a1>>a2>>a3>>b1>>b2>>b3>>c1>>c2>>c3>>d1>>d2>>d3;
			cout<<max({a1+b2+c3+d1,a1+b2+c3+d2,a1+b2+c3+d3,a1+b3+c2+d1,a1+b3+c2+d2,a1+b3+c2+d3,a2+b1+c3+d1,a2+b1+c3+d2,a2+b1+c3+d3,a2+b3+c1+d1,a2+b3+c1+d2,a2+b3+c1+d3,a3+b1+c2+d1,a3+b1+c2+d2,a3+b1+c2+d3,a3+b2+c1+d1,a3+b2+c1+d2,a3+b2+c1+d3,
					   b1+c2+d3+a1,b1+c2+d3+a2,b1+c2+d3+a3,b1+c3+d2+a1,b1+c3+d2+a2,b1+c3+d2+a3,b2+c1+d3+a1,b2+c1+d3+a2,b2+c1+d3+a3,b2+c3+d1+a1,b2+c3+d1+a2,b2+c3+d1+a3,b3+c1+d2+a1,b3+c1+d2+a2,b3+c1+d2+a3,b3+c2+d1+a1,b3+c2+d1+a2,b3+c2+d1+a3,
					   c1+d2+a3+b1,c1+d2+a3+b2,c1+d2+a3+b3,c1+d3+a2+b1,c1+d3+a2+b2,c1+d3+a2+b3,c2+d1+a3+b1,c2+d1+a3+b2,c2+d1+a3+b3,c2+d3+a1+b1,c2+d3+a1+b2,c2+d3+a1+b3,c3+d1+a2+b1,c3+d1+a2+b2,c3+d1+a2+b3,c3+d2+a1+b1,c3+d2+a1+b2,c3+d2+a1+b3,
					   d1+a2+b3+c1,d1+a2+b3+c2,d1+a2+b3+c3,d1+a3+b2+c1,d1+a3+b2+c2,d1+a3+b2+c3,d2+a1+b3+c1,d2+a1+b3+c2,d2+a1+b3+c3,d2+a3+b1+c1,d2+a3+b1+c2,d2+a3+b1+c3,d3+a1+b2+c1,d3+a1+b2+c2,d3+a1+b2+c3,d3+a2+b1+c1,d3+a2+b1+c2,d3+a2+b1+c3})<<"\n";
		}else{
			int a1=0,a2=0,a3=0;
			for(int i=1;i<=n;i++){
				cin>>a[i].a1>>a[i].a2>>a[i].a3;
				a1+=a[i].a1;
				a2+=a[i].a2;
				a3+=a[i].a3;
			}
			if(a2==0&&a3==0){
				sort(a+1,a+n+1,cmp1);
				int ans=0;
				for(int i=1;i<=n/2;i++){
					ans+=a[i].a1;
				}
				cout<<ans<<"\n";
			}else{

			}
			
		}
		
		
	}
	return 0;
}
/*
5

a1+b2+c3+d4+e5+f1+g1+h1+i1+j1
*/
