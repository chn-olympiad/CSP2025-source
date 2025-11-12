#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(n==1){
		int temp;
		cin>>temp;
		if(n==k){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(n==2){
		int t1,t2;
		cin>>t1>>t2;
		int ans=0;
		if(t1==k){
			ans++;
		}
		if(t2==k){
			ans++;
		}
		if(t1!=t2){
			ans++;
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
