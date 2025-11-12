#define WW long long;
#include <stdio.h>
#include<bits/stdc++.h>
void solve()
{
	int n;
	cin>>n;
	int count1 =0;
	int count2 =0;
	int count3 =0;
	int a1[n],a2[n],a3[n];
	for(int i=0;i<n;i++)
    {
		cin>>a1[i]>>a2[i]>>a3[i];
		if(a2[i]==0)count2++;
		if(a3[i]==0)count3++;
	}
	
int main()
{
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    
	return 0;
}
