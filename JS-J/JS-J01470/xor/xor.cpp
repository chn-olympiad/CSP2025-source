#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,s=0,s1=0;
	cin>>n>>k;
	
	if(k==0){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			if(a[i]==1&&a[i+1]==1&&i!=n){ 
				i++;
				s++;
			}
			else if(a[i]==0) s++;
		}
		cout<<s;
	} 
	else if(k==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			if(a[i]==1) s1++;
		}
		cout<<s+s1;
	}
	return 0;
}
