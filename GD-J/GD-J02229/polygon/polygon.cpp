#include<bits/stdc++.h>
using namespace std;
int n,c_i,ans,themax;
int s[5050],ss[5050],l=1;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>c_i;
		ss[c_i]++;
	}
	for(int i=1;i<=5000;i++)
	{
		while(ss[i]>0){
		s[l]=i;ss[i]--;l++;}
	}
	themax=max(max(s[1],s[2]),s[3]);
	if(s[1]+s[2]+s[3]>themax*2)cout<<1;
	else cout<<0;
	return 0;
}
