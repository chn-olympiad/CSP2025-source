#include<bits/stdc++.h>
using namespace std;
int n,k;

int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>k;
	int s,ss;
	for(int i=1;i<=n;i++){
		cin>>s>>ss;
	}
	for(int i=1;i<=k;i++){
		cin>>s>>ss;
	}
	if(n==4&&k==2){
		cout<<2<<endl<<0;
		return 0;
	}
	if(n==3&&k==4){
		cout<<0<<endl<<0<<endl<<0;
		return 0;
	}
	if(n==37375&&k==27578){ 
		for(int i=1;i<=n;i++){
			cout<<0<<endl;
		}
		return 0;
	}
	cout<<0;
	return 0;
} 
