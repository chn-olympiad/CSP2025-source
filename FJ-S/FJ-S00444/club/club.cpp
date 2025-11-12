#include<bits/stdc++.h>
using namespace std;
struct node{
	int a1,a2,a3;
}a[100010];
long long ans=-1e9;
int n;
int sum1,sum2,sum3;
long long f[100010][5];
bool cmp1(node a,node b){
	return a.a1>b.a1;
}
bool cmp2(node a,node b){
	if(a.a1!=b.a1)return a.a1>b.a1;
	return a.a2>b.a2;
}
void dfs(int k,long long sum){
	if(k==n+1){
		ans=max(sum,ans);
		return;
	}
	for(int j=1;j<=3;j++){
		dfs(k+1,sum+a[k].a1);
		dfs(k+1,sum+a[k].a2);
		dfs(k+1,sum+a[k].a3);
	}
	return;
}
void sol1(){
	long long sum=0;
	sort(a+1,a+n+1,cmp1);
	for(int i=1;i<=n;i++){
		if(sum1<=n/2){
			sum+=a[i].a1;
		}
	}
	cout<<sum<<endl;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		sum1=0,sum2=0,sum3=0;
		ans=0;
		cin>>n;
		bool f1=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a2!=0){
				f1=0;
				
			}
			if(a[i].a3!=0){
					f1=0;
			}
		}
		if(n<=200){
			dfs(1,0);
		}else if(f1==1){
			sol1();
		}
		cout<<ans<<endl;
	}
	return 0;
}
