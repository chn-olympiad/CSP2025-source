#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum0=0,sum1=0;
	cin>>n>>k;
	vector<int>b;
	int a[n];
    bool f1=true,f2=true;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	if(a[i]==1){
    		sum1+=1;
    		b.push_back(i);
		}
    	else f1=false;
    	if(a[i]>1)f2=false;
    	if(a[i]==0)sum0+=1;
	}
	if(f1&&k==0)cout<<n/2;
	if(f2&&k==0)
	{
		for(int i=1;i<b.size();i++)
		{
			if(a[i]==1&&a[i-1]==1){
				i+=1;
				sum0+=1;
			}
		}
		cout<<sum0;
	}
	if(f2&&k==1)cout<<sum1;
	return 0;
}
