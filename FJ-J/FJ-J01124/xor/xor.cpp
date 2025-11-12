#include<bits/stdc++.h> 
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,t=0,s=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)t++;
	}if(k==1)cout<<t;
	else{
		for(int i=1;i<=n;i++){
			if(!a[i])s++;
			else{
				if(a[i]==a[i+1])s++,i++;
			}
		}cout<<s;
	}
	return 0;
}
