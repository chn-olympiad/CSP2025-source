#include<bits/stdc++.h>
using namespace std;
int n,k,num0,num1;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			num1++;
		}
		if(a[i]==0){
			num0++;
		}
	}
//	cout<<num0<<" "<<num1<<endl;
	if(k==0){
		cout<<num1/2+num0;
		return 0;
	}else if(k==1){
		cout<<num1;
		return 0;
	}
	return 0;
}
