#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=1e5+10;
struct node{
	ll s1,s2,s3;
}a[N],b[N],c[N];

bool cmp1(node x,node y){
	return x.s1>y.s1;
}
bool cmp2(node x,node y){
	return x.s2>y.s2;
}
bool cmp3(node x,node y){
	return x.s2>y.s2;
}
int main(){
//	freopen(" .in","r",stdin);
//	freopen(" .out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,sum=0;
		ll ans=0;
		cin>>n;
		sum=n/2;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			a[i].s1=x,a[i].s2=y,a[i].s3=z;
			b[i].s1=x,b[i].s2=y,b[i].s3=z;
			c[i].s1=x,c[i].s2=y,c[i].s3=z;
		}
		sort(a+1,a+1+n,cmp1);
		sort(b+1,b+1+n,cmp2);
		sort(c+1,c+1+n,cmp3);
		ll ans1=0,ans2=0,ans3=0;
		for(int i=1;i<=sum;i++){
			ans1+=a[i].s1;
			ans2+=b[i].s2;
			ans3+=c[i].s3;
		}
		for(int i=sum+1;i<=n;i++){
			ans1+=max(a[i].s2,a[i].s3);
			ans2+=max(b[i].s1,b[i].s3);
			ans3+=max(c[i].s1,c[i].s2);
		}
		cout<<max(ans1,max(ans2,ans3))<<"\n";
	}
	return 0;
} 
