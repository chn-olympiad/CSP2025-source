#include<bits/stdc++.h>
using namespace std;
int nums1=0;
int n1=0,n2=0,n3=0;
struct numbers
{
	int a1,a2,a3;
}nbs[100000];
int dg(int he,int n,int num)
{
    if(num>=5)
    {
        return he;
    }
    if(n1>n/2)
	{
		return 0;
	 }
	else if(n2>n/2)
	{
		return 0;
	 }
	else if(n3>n/2)
	{
		return 0;
	 }
    nums1=max(nums1,he);
    int h1=he+nbs[num].a1;
    int h2=he+nbs[num].a2;
    int h3=he+nbs[num].a3;
	
	num=num+1; 
	n1++;
    dg(h1,n,num);
    n1--;
    n2++;
	dg(h2,n,num);
	n2--;
	n3++;
    dg(h3,n,num);
	return 0;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	
	for(int f=0;f<t;f++)
	{
		nums1=0;
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>nbs[i].a1;
			cin>>nbs[i].a2;
			cin>>nbs[i].a3;
		}
		dg(0,n,0);
        cout<<nums1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
