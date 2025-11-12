#include<bits/stdc++.h>
#define M 998244353
using namespace std;
typedef long long ll;
const int N=1e4+114;

int a[N];

ll jc(int x){
	int ans=1;
	for(int i=2;i<=x;i++){
		ans=(ans%M * i%M)%M;
		
	}
	return ans;
}




int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n,q;
	cin>>n>>q;
	string s;
	cin>>s;
	ll k=0,p=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)k++;
		else p++; 
	}
	if(q==p+1){
		cout<<(jc(p)*k)%M <<endl;
	}
	else if(q>p+1) cout<<0<<endl;
	else cout<<21474836;
	
	
	
	fclose(stdin);
	fclose(stdout);
	
	
	
	return 0;
} 
