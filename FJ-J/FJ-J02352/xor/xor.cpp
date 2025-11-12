#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(k==0){
		bool s=true;
		for(int i=0;i<n;i++){
			if(a[i]!=1) s=false;
		}
		if(s==true){
			cout<<n/2;
		}
		else{
			int last=0;
			for(int i=1;i<n;i++){
				if(a[i]==a[last]){
					cnt++;
					last+=2;
					i++;
				}
				else last++;
			}
			cout<<cnt;
		}
	}
	else if(k==1){
		int last=0;
		for(int i=1;i<n;i++){
			if(a[i]!=a[last]){
				cnt++;
				last+=2;
				i++;
			}
			else last++;
		}
		cout<<cnt;
	}
	return 0;
}
