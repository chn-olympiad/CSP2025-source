#include<bits/stdc++.h>
using namespace std;

int n,l=1,r,d=2,ax,h,s;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int a[n+5];
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
	}
	for(int i=2;i<=n-1;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			h=0;
			//l=j,r=j+i
			for(int k=j;k<=j+i;k++){
				h+=a[k];
				if(a[k]>=ax) ax=a[k];
			}
			h=h-ax;
			if(h>ax)
			{
				//cout<<h<<"!"<<endl;
				s+=1;
			}
		}
	}
	cout<<s%998244353;
    return 0;
}
