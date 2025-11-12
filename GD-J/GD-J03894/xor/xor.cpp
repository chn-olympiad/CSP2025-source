#include<bits/stdc++.h> 
using namespace std;
int n,k,sum1,ans=0;
int a[500050];
int main(){	
	int cnt = 0;
	freopen("xor.in","r",stdin); 
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(a[i] == 0){
			cnt++;	
		}else{
			ans += (cnt*(cnt+1))/2;
			cnt = 0;
		}
	}
	if(a[n] == 0){
		ans += (cnt*(cnt+1))/2;
	}
	if(k == 0){
		cout<<ans;
	}else{
		cout<<1; 
	}
	return 0;
}
