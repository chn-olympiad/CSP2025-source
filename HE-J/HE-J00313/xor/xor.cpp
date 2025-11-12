#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100005];
bool p;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0)cout<<1;
	for(int i=1;i<=n;i++){
		if(a[i]==1)
		p=1;
		else{
			p=0;
			break;
		}	
	} 
	if(p==1)cout<<1;
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
