#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int ma=2e5+5;
int a[ma],b[ma],c[ma];
int num1,num2,num3,sum=0,n,ans=0;
void dfs(int idx){
	if(idx==n+1){
		ans=max(sum,ans);
		return;
	}
	if(num1<n/2){
		num1++;
		sum+=a[idx];
		dfs(idx+1);
		sum-=a[idx];
		num1--;
	}
	if(num2<n/2){
		num2++;
		sum+=b[idx];
		dfs(idx+1);
		sum-=b[idx];
		num2--;
	}
	if(num3<n/2){
		num3++;
		sum+=c[idx];
		dfs(idx+1);
		sum-=c[idx];
		num3--;
	}
	
	return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
		dfs(1);
		cout<<ans<<" ";
	}
	return 0;
}
