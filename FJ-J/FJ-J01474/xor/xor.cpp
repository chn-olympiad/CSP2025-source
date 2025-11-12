#include<iostream>
using namespace std;

int n,k,a[500005],ans;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
	cin>>a[i];
	if(a[i]==1)
	ans++;
}
	if(ans==n){
	cout<<n/2;
	return 0;
}
	else
	{
		ans=0;
		if(k==1){
		for(int i=1;i<=n;i++){
		    if(a[i]==1)
			ans++; 
		}
		cout<<ans;
	}
	    else if(k==0){
	    	for(int i=2;i<=n;i++){
	    		if(a[i]==a[i-1]&&a[i]==0)
	    		{
	    		ans+=2;
	    		a[i]=a[i-1]=-1;
	    	}
	    		else if(a[i]==a[i-1])
	    		{
	    		ans++;
	    		a[i]=a[i-1]=-1;
	    	}
	    	    else if(a[i]==0){ans++;a[i]=-1;}
	    	    else if(a[i-1]==0){ans++;a[i-1]=-1;}
		}
		cout<<ans;
		}
	}
	return 0;
}
