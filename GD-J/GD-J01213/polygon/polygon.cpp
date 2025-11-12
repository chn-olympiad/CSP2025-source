#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5010];
int ma,ans;
void f(int x,int sum,int r){
	if(r==1){
		if(sum>=ma*2){
			ans++;
		}
	}
	else f(x+1,sum+a[x+1],r-1);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0;
	cin>>n;
	if(n<=3){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum+=a[i];
			ma=max(ma,a[i]);
		}
		if(sum>=ma*2){
			cout<<1;
			return 0;
		}
	}
	else f(1,a[1],n);
	cout<<ans;
	return 0;
} 
