#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector<int>a(n+1);
	bool p=1,p2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)
		p=0;
		if(a[i]!=1&&a[i]!=0)
		p2=0;
	}
	if(!n){
		cout<<0;
	}else if(p){
		if(k==0){
			cout<<n/2;
		}else{
			cout<<n;
		}
	}else if(p2){
		if(k==1){
			int i=1,o=0;
			while(i<=n){
				if(a[i]){
					o++;
				}i++;
			}
			cout<<o;
		}else if(!k){
			int i=1,o=0;
			while(i<=n){
				if(!a[i]){
					o++; 
				}else if(i<n&&a[i]==a[i+1]){
					o++;
					i++;
				}
				i++;
			}
			cout<<o;
		}
		}else{
			if(!k){
				int o=0;
				for(int i=1;i<=n;i++){
					if(!a[i]){
						o++;
					}else if(i<n&&a[i]==a[i+1]){
						o++;
						i++;
					}
				}
				cout<<o;
			}else{
				int o=0;
				for(int i=1;i<=n;i++){
					if(a[i]==k)
					o++;
				}
				cout<<o;
			}
		}
	return 0;
}
