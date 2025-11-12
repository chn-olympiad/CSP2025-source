#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s[1500005],s2[1500005],sum,last;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];  
	for(int i=0;i<=1500000;i++)s[i]=-1;
	s[0]=0;
	for(int l=1,r=1;r<=n;r++){
		s2[r]=s2[r-1]^a[r];
		if(s[s2[r]^k]+1>=l){
			sum++,l=r+1;
		}
		s[s2[r]]=r;
	}  
	cout<<sum;
	return 0;
} 
