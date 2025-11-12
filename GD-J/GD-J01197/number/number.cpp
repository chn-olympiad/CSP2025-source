#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[1000005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;int sum=0;
    cin>>s;
    k=s.size();
    for(int i=0;i<k;i++)
    {
    	if(s[i]>='0'&&s[i]<='9')
    	{
    		sum++;
    		a[sum]=s[i]-'0';
		}
	}
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=sum;i++) cout<<a[i];
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
