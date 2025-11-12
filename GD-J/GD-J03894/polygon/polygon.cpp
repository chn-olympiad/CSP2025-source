#include<bits/stdc++.h> 
using namespace std;
int n;
int a[5050];
int main(){
	freopen("polygon.in","r",stdin); 
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int p=1,ans=0;
	if(a[n] == 1){
		for(int j = 1;j <= 3;j++){
			p = p * (n-j+1);
		} 
		for(int j = 1;j <= 3;j++){
			p = p / j;
		}
		ans += p;
		for(int i = 4;i <= n;i++){
			p = p * (n-i+1);
			p = p / i;
			ans += p;
		}
	} 
	cout<<ans;
	return 0;
}
