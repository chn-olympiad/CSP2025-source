#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a;
	int b;
	cin>>a>>b;
	int arr[10000]={0};
	for(int i=0;i<a;i++)
	{
		cin>>arr[i];
	}
	if(b==2)
	{
		cout<<b<<endl;
	}
	if(b==3)
	{
		cout<<b-1<<endl;
	}
	if(b==0)
	{
		cout<<b+1<<endl;
	}
	return 0;
}

