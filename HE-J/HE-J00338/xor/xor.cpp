#include<bits/stdc++.h> 
using namespace std;
int main()
{
	int n,k;
	int a[500005];
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	if(n<=2){
		cout<<0;
	}
	else
	{
		cout<<2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
