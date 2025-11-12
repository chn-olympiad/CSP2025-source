#include<bits/stdc++.h>
using namespace std;
int a[500010];
bool b[10];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,x,sum=0,temp;
	bool flag=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k)
		sum++;
		else if(n!=i&&a[i+1]!=k)	
		sum++; 
	}
	cout<<sum;
	return 0;
}