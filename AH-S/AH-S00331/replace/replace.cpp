#include<bits/stdc++.h>
using namespace std;
char a[1003][1003],b[1003][1003];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >>n >>q;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin >>s1 >>s2;
		int s1s=s1.size();
		int begin=0,finish=0;
		for(int j=0;j<s1s;j++)
		{
			if(s1[j]!=s2[j])
			{
				begin=j;
				break;
			}
		}
		for(int j=s1s-1;j>=0;j--)
		{
			if(s1[j]!=s2[j])
			{
				finish=j;
				break;
			}
		}
		string s3=s1.substr(begin,finish-begin+1);
		string s4=s2.substr(begin,finish-begin+1);
		int s3s=s3.size();
		for(int j=0;j<s3s;j++)
		{
			a[i][j]=s3[j];
			b[i][j]=s4[j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		string t1,t2;
		cin >>t1 >>t2;
		if(t1.size()!=t2.size())
		{
			cout <<0 <<endl;
			continue;
		}
		int be,fi,t1s=t1.size();
		for(int j=0;j<t1s;j++)
		{
			if(t1[j]!=t2[j])
			{
				be=j;
				break;
			}
		}
		for(int j=t1s-1;j>=0;j--)
		{
			if(t1[j]!=t2[j])
			{
				fi=j;
				break;
			}
		}
		string A=t1.substr(be,fi-be+1);
		string B=t2.substr(be,fi-be+1);
		int sum=0,sAs=A.size();
		for(int i=1;i<=n;i++)
		{
			int flag=1;
			for(int j=0;j<sAs;j++)
			{
				if(a[i][j]!=A[j] || b[i][j]!=B[j])
				{
					flag=0;
					break;
				}
			}
			if(flag==1) sum++;
		}
		cout <<sum <<endl;
	}
	return 0;
}
