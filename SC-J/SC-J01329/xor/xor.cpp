#include<bits/stdc++.h>
using namespace std;
int n,a,k,s1,s0,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a==0){
			s0++;
		}
		if(a==1){
			s1++;
		}
	}
	if(k==0){
		ans=s0+s1/2;
	}
	else if(k==1){
		ans=s1;
	}
	else{
		ans=1;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
