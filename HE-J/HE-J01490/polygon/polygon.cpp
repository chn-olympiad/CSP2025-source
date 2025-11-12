#include<iostream>
using namespace std;
int main()
{
    freopen("polygon","r",stdin);
    freopen("polygon","w",stdout);
	int n,a[5001],b[5001],k=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<3)
	{
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		k+=a[i];
	}
	for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		b[i]=a[i];
    		if(a[i]<=a[i+1]){
    			a[i]=a[i+1];
    			a[i+1]=b[i];
			}
		}
    }
    if(a[1]>=k)
    {
    	cout<<"0";
    	return 0;
	}
	cout<<"1";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
