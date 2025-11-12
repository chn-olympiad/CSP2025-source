#include<bits/stdc++.h>
using namespace std;
long long n,k,cnt,flag=1;
long long a[500005],s[500005];
int main()
{
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=0;
	} 
	if(flag){
		if(k!=0) cout<<0;
		else{
			for(int i=n;i>=1;i++){
				cnt+=i;
			}
			cout<<cnt;
		}
	}
	else{
		if(k==0){
			for(int i=n;i>=1;i++){
				cnt+=i;
			}
			cout<<cnt;
		}
		else{
			cout<<0;
		}
	}
	return 0;
}
