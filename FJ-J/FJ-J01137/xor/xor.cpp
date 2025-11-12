#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],maxai,ans;
void solve1(){
	int one=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			one++;
		}
	}
	if(k==1){
		cout<<one;
		return ;
	}else{
		for(int i=1;i<n;i++){
			if(a[i]==1&&a[i+1]==1){
				i++;
				one--;
			}
		}
		cout<<n-one;
		return ;
	}
}
void solve2(int l,int sum){
	if(l>n){
		ans=max(ans,sum);
	}
	for(int i=l;i<=n;i++){
		int x=0;
		for(int j=i;j<=n;j++){
			x^=a[j];
			if(x==k){
				solve2(j+1,sum+1);
			}else if(j==n){
				solve2(j+1,sum);
			}
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxai=max(maxai,a[i]);
	}
	if(maxai<=1&&k<=1){
		solve1(); 
	}else{
		solve2(1,0);
		cout<<ans;
	}
	return 0;
}
