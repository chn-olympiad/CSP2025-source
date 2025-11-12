#include<bits/stdc++.h>
using namespace std;
int a[100005];
int n,k;	
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool i1=1,i2=1;	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) i1=0;
		if(a[i]!=1&&a[i]!=0) i2=0;
	}
	if(i1==1){
		if(k==0) cout<<n/2;
	}else if(i2==1){
		int s0=0,s1=0,n1=0;
		if(k==0){			
			for(int i=1;i<=n+1;i++){
				if(a[i]==0&&i!=n+1) s0++;
				if(a[i]==1) n1++;
				if(n1>0&&a[i]==0){
					s1+=n1/2;
					n1=0;
				}
			}
			cout<<s0+s1;
		}else if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1) s1++;
			}
			cout<<s1;
		}
	}
	return 0;
}
