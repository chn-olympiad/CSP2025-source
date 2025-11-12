#include <bits/stdc++.h>
using namespace std;
const int N=998244353;
long long sum,sum1,sum2;
int n,a[5100];
long long dfs(int l,int step,int mx,int z){
	int sum=0;
	//cout<<l<<" "<<step<<" "<<mx<<" "<<z<<endl;
	if(step==n+1){
		//cout<<l<<" "<<mx<<" "<<z<<endl;
		if(l>=3 && z>mx*2){
			return 1;
		}else{
			return 0;
		}
	}
	sum+=dfs(l+1,step+1,max(a[step],mx),z+a[step]);
	if(l+n-step+1>3){
		sum+=dfs(l,step+1,mx,z);
	}
	return sum%N;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    int flag=1;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]!=1){
    		flag=0;
		}
	}
	if(flag){
		for(int i=3;i<=n;i++){
			sum1=1;
			sum2=1;
			for(int j=1;j<=i;j++){
				sum1*=j;
				sum1%=N;
			}
			for(int j=n;j>=n-i+1;j--){
				sum2*=j;
				sum2%=N;
			}
			sum+=(sum2/sum1)%N;
		}
		cout<<sum;
		return 0;
	}
	cout<<dfs(0,1,0,0)%N;
	return 0;
}
