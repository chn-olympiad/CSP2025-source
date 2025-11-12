#include<bits/stdc++.h>
using namespace std;
int n,k,a[514000];
bool flag=false;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!a[i])flag=true;
	}
	if(!flag)cout<<0;
	else{
		int yi=0,ling=0;
		for(int i=1;i<=n;i++){
			if(a[i])yi++;
			else ling++;
		}
		if(k=0)cout<<ling;
		else cout<<yi;
	}
	return 0;
}
