#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans,al,bj;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;)
	{
		bj=0;
		for(int j=i;j<=n;j++)
     	{
			if(j==i)al=a[j];
			else al=al^a[j];
			if(al==k)
			{
			    ans++;
			    bj=j;
			    break;
			}	
    	}
    	if(bj==0)i++;
    	else i=bj+1;
	}
	cout<<ans;
	
	return 0;
} 
