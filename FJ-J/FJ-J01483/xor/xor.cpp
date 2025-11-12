#include<bits/stdc++.h>
using namespace std;
int n,k,c[500005];
bool a=1,b=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(c[i]!=1)a=0;
		if(c[i]>1)b=0;
	}
	if(k==0 && a)cout<<n/2;
	else if(k<=1 && b){
		int p=0;
		for(int i=0;i<n;i++){
			if(c[i]==1){
				p++;
				
			}
		}
		if(k)cout<<p;
		else cout<<p/2;
	}
	else{
		//
		
	}
	
	return 0;
} 

