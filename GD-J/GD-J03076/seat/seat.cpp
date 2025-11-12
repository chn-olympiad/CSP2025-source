#include<bits/stdc++.h>
using namespace std;
int ac[15][15];
int b[1000005];
int main(){
ifstream fin("seat.in");
ofstream fout("seat.out");
	int n,m;
	fin>>n>>m;
	for(int i = 0;i<n*m;i++)
	{
		fin>>b[i];
	}
	int c = b[0];
	sort(b,b+n*m);
	int k = n*m-1;
	for(int i =0;i<m;i++)
	{
		if(i%2 != 0)
		{
			for(int j = n-1;j>=0;j--)
			{	
				if (c == b[k])
				{
					fout<<i+1<<" "<<j+1;	
					fin.close();
					fout.close();
					return 0;
				}
				else
				{
					k--;
				}
			}
		}
		else
		{
			for(int j = 0;j<n;j++)
			{	
				if (c == b[k])
				{
					fout<<i+1<<" "<<j+1;
					fin.close();
					fout.close();
					return 0;
				}	
				else
				{
					k--;
				}
			}	
		}
	}
}
