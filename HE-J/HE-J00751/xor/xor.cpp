#include<bits/stdc++.h>
using namespace std;
int a[510000]={0},j,k,n,m,o=0,t,g=1; 
void doing(int i)
{
	if(i>n)return;
	else
	{
		t=t^a[i];
		if(t==k){o++;return;}
		else doing(i+1);
		t=a[i];
		doing(i+1);
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	t=a[1];
	doing(1);
	cout<<o-1;
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
