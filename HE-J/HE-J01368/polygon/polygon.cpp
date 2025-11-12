#include<bits/stdc++.h>
using namespace std;
int n,sum;
int main(){
	cin >> n;
	int l[n+1];
	for(int p=1;p<=n,p++){
		cin >> l[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=n;j++)
		{
			for(int k=3;k<=n;k++)
			{
				if(a[i]+a[j]+a[k]>max(a[i],a[j],a[k]) and max(a[i],a[j],a[k])<(a[i]+a[j]+a[k]-max(a[i],a[j],a[k])))
				{
					sum++;
				}
			}
		}
	}
	cout << sum++;
}
