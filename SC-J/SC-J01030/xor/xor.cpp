#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500009];
long long k;



int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=1,r=1,s=0,ans=0;
	while(l<=n){
		for(int i=l;i<=r;i++){
			s=s^a[i];
		}
		if(s==k){
			ans++;
//			cout<<l<<" "<<r<<endl;
			l=r+1;
			r=l;
		}
		else {
			r++;
			if(r>n){
				l++;
				r=l;
			}
		}
		s=0;
	}
	cout<<ans;

	
	
	return 0;
} 