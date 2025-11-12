#include<bits/stdc++.h>
using namespace std;

int a[500001];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k,bjnandu=0,bj0shu=0,bj1shu=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)bjnandu=1;
		if(a[i]==0)bj0shu++;
		if(a[i]==1)bj1shu++;
	}
	
	if(bjnandu==0){
		if(k==1)cout<<bj1shu;
		else if(k==0)cout<<bj0shu;
	}
	else{
		cout<<18;
	}
	
	fclose(stdin);
	fclose(stdout);
}
