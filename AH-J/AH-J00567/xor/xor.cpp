#include<bits/stdc++.h>
using namespace std;
int n,k,x1=0,x2=0;
int a[5000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1&&a[i-1]!=0){
			x1++;
		}
		if(a[i]==0&&a[i-1]!=0){
			x2++;
		}
	}
	if(k==0){
		cout<<0;
		return 0;
	}
	else{
		if (k==0)cout<<x2;
		else{
			cout<<x1;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
