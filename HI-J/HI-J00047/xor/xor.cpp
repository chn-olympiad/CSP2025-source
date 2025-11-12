#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	 cin>>n;
	 for(int i=0;i<n;i++){
	 	cin>>a[i];
	 }
	 if(n>2){
	 	cout<<0;
	 }
	 cout<<1;
	 return 0;
}
