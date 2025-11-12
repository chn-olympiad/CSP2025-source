#include<bits/stdc++.h>
using namespace std;
int a[100]={0};
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	int k;
	int ans;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		k++;
	}
    int w=0;
    w=w+n;
	ans=n/2;
	cout<<ans;
	return 0;
}
