#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int mat[1000000];
	int n,num;
	string s;
	cin>>s;
	int j = 0;
	for(int i = 0;i<s.size();i++)
	{
		if(s[i]-'0'<='9'-'0'&&s[i]-'0'>=0)
		{
			mat[j] = s[i]-'0';
			j++;
		}	
	}
	for(int i = 0;i<j;i++)
	{
		for(int k =0;k<j-i-1;k++)
		{
			if(mat[k]<mat[k+1])
			{
				num = mat[k];
				mat[k] = mat[k+1];
				mat[k+1]= num;
			}
		}
	}
	for(int i = 0;i<j;i++)
	{
		n+=pow(10,j-i-1)*mat[i];
	}
	cout<<n;
	return 0;
}