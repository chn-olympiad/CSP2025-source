#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long n,k,js=0;
long long a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
		}
	if(n==1&&a[1]!=k){
		cout<<0;
		return 0;
		}
    if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				js++;
				}
			else if(a[i]==1&&a[i+1]==1){
				i++;
				js++;
				}
			}	
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]){
				i++;
				js++;
			}
		}
	}
	cout<<js;
	return 0;
	}
