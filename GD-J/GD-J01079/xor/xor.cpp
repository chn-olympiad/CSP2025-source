#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+114;

int a[N],s[N];


int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	
	ll n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	//for(int i=1;i<=n;i++) cout<<s[i]<<" ";
	//cout<<endl;
	//cout<<(s[1]^s[0])<<endl;
	ll cnt=0;
	ll l=1,r=1,lst=1;
	while(r<=n){
		
		while((s[r]^s[l-1])!=k && l<=r) l++;
		if((s[r]^s[l-1])==k) {
			cnt++;
			//cout<<l<<" "<<r<<endl;
			lst=++r;
			l=lst;
			continue;
		}
		r++,l=lst;
	}
	cout<<cnt;
	
	
	
	fclose(stdin);
	fclose(stdout);
	
	
	
	
	return 0;
} 
