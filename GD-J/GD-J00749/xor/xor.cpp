#include<bits/stdc++.h>
using namespace std;

int num[200086];
int a;
int n,k;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		if(num[i]==1){
			a++;
		}
	}
	if(k==0){
		cout<<a/2;
	} 
	else{
		cout<<a;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
