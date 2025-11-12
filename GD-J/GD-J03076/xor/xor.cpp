#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	ifstream fin("xor.in");
	ofstream fout("xor.out");
	int n,k;
	fin>>n>>k;
	for(int i = 0;i<n;i++){
		fin>>a[i];
	}
	int l = 0,r = 0,c = 0,cc = 0,ll = 0,lr = 0;
	for(int i = 0;i<n;i++)
	{
		if (a[i] == k)
			c++;
		for(int j = l;j<r;j++)
		{
			int x = a[j];
			int y = a[j+1];
			if (j == l)
				c = x^y;
			else 
				c = c^(x^y);			
		}
		if (c == k)
		{
			if (r+1<n)
			{
				l = r+1;
				r = l;
			}
			if (i!=0)
			{
				if (l<ll and r>lr)
				{
					ll = l;
					lr = r;
				}
				else
				{
					cc++;
				}
			}
			ll = l;
			lr = r;
		} 
		else
		{
			c = 0;
			if (r+1<n)
			{
				r++;
			}
		}
	}
	fout<<cc;
	fin.close();
	fout.close();
}
