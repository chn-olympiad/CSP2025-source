#include<bits/stdc++.h>
using namespace std;
long long k;
long long a[500005],b,t[500005];
long long n;
string s;

int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int ans=0;
	cin>>n>>k;
	cin>>a[0];
	for(int i=1;i<n;i++){
		cin>>b;
		a[i]=a[i-1]^b;
	} 
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i;j++){
			if(j>0&&abs(a[j+i]-a[j-1])==k||j==0&&abs(a[j+i]-0)==k){
				int y=1;
				for(int k=j;k<=j+i;k++){
					if(t[k]==1){
						
						y=0;
					}
				}

				if(y){
					for(int k=j;k<=i+j;k++){
						t[k]=1;
					}	
					ans++;
				}
			}
		}
	}
	
	cout<<ans;
	return 0;
} 
