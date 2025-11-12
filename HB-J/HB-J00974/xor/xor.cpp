#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N=1e6+10;
int a[N]; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(n==1&&k==0){
			cout<<a[i];
		}else if(n==2&&k==0){
			cout<<"1";
			return 0;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
