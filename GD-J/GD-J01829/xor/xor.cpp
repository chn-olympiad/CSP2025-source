#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],s1,s2,s3,b[500005],maxx;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
		if(a[i]==k)s1++,b[s1]=i;
	}
	b[0]=0,b[s1+1]=n+1;
	if(k==0)
	{
		for(int i=2;i<=n;i++)
		if(a[i]!=0&&a[i]==a[i-1])s2++;
		cout<<s1+s2;
		return 0;
	}
	if(maxx==1&&k==1)
	{
		cout<<s1;
		return 0;
	}
	for(int i=1;i<=s1+1;i++)
	{
		for(int x=b[i-1]+1;x<b[i]-1;x++)
		{
			//long long o=x;
			long long t1=0,t2=a[x]^k;
			///cout<<t2<<"  ";
			for(int j=x+1;j<b[i];j++)
			{
				t1=t1^a[j];
				cout<<x<<" "<<j<<" "<<t1<<" "<<t2<<" "<<s3<<endl;
				if(t1==t2)
				{
					s3++,x=j;
					break;
				}
			}
		//	x=o;
		}		
	}
	cout<<s1<<" "<<s2<<" "<<s3<<endl;
	cout<<s1+s2+s3;
	return 0;
}
