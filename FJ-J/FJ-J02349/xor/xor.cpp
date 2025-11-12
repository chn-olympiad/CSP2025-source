#include<bits/stdc++.h>
using namespace std;
int n,k,s[500005],p;
bool flag=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]==0) flag=1;
		if(s[i]==1) ++p;
	}
	if(flag==1){
		if(k==1){
			cout<<p;
		}
		if(k==0){
			int sum=n-p;
			for(int i=1;i<=n;i++){
				if(s[i]==1&&s[i+1]==1){
					i++,sum++;
				}
			}
			cout<<sum;
		}
		return 0;
	}
	if(k==0){
		cout<<n/2;
		return 0;	
	}
	return 0;
}
