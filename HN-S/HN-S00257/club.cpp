#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,cnt1,cnt2,cnt3;
int maxn,n;
int main(){
	cin>>t;
	while(t--){
		cin>>n; 
			for(int i=1;i<=n;i++){
				cin>>cnt1>>cnt2>>cnt3;
				if(cnt1>=cnt2 || cnt1>=cnt3) maxn+=cnt1;
				if(cnt2>=cnt1 || cnt2>=cnt3) maxn+=cnt2;
				if(cnt3>=cnt2 || cnt3>=cnt1) maxn+=cnt3;
			}
	    }
	return 0;
} 
