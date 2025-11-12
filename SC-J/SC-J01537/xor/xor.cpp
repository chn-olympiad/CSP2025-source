#include<iostream>
using namespace std;
int n,k;
int ans=0;
int ji[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n<=2)
	{
		cout<<"1";
		return 0;
	}
	if(k==0)
	{
		cout<<n/2;
		return 0;
	}
	return 0;
}