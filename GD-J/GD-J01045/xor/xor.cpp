#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int m=0,s=0;
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) m++;
	}
	if(k==1) cout<<m;
	else{
		for(int i=1;i<=n;i++){
			if(a[i]==1&&a[i+1]==1){
				s++;
				a[i]=0;
				a[i+1]=0;
			}
		}
		cout<<n-m+s;
	}	
}
