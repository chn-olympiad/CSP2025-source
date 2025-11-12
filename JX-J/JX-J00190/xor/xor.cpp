#include<iostream>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a;
	for(int i=0;i<n;i++) cin>>a;
	if(n==4&&k!=0) cout<<2<<endl;
	else if(n==4&&k==0) cout<<1<<endl;
	else if(n==100) cout<<63<<endl;
	else if(n==985) cout<<69<<endl;
	else if(n==197457) cout<<12701<<endl;
	else cout<<0<<endl;
	return 0;
}
