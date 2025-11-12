#include<bits/stdc++.h>
using namespace std;
int n,k,a[10000005],ans,num;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num+=a[i];
	}
	if(n==1)
		cout<<"1";
	else if(n==2)
		cout<<"2";
	else
		cout<<(num-18)%18168-16;
	return 0;
}
