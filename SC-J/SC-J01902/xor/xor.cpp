#include<bits/stdc++.h>
using namespace std;
int a[500009],n,k,s,z=-1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k&&z==-1){
			s++;
			z=-1;
			
		}
		else{//cout<<s;
			if(z==-1){
				z=a[i];
				continue;
			}
			if(z!=a[i])z=1;
			else z=0;
			if(z==k){
				s++;
				z=-1;
			}
		}
	}cout<<s;
	
	return 0;
}