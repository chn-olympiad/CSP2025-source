#include<bits/stdc++.h>
using namespace std;
int n,a[100010],s1,s0,k,s02,s12;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	a[0]=2;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			s1++;
			if(a[i-1]==1){
				s02++;
				a[i]=2;
				a[i-1]=2;
			}else if(a[i+1]==1){
				s02++;
				a[i]=2;
				a[i-1]=2;
			}
		}else{
			s0++;
		}
	}
	if(k==1){
		cout<<s1;
	}else{
		cout<<s0+s02;
	}
	return 0;
}
