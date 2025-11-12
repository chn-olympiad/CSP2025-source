#include<bits/stdc++.h>

using namespace std;

int n,a[5010],p=0,ans=0;
bool is=false;
vector<int> v;

void f(int k,int m)
{
	if(k>m)
	{
		if(p>a[m]*2) ans++;
		else is=true;
	}
	else
	{
		for(int i=k;i<=m;i++)
		{
			v.push_back(a[i]);
			p+=a[i];
			f(i+1,m);
			p-=a[i];
			v.pop_back();
			if(is)
			{
				is=false;
				continue;
			}
		}
	}
}

int main()
{
	ifstream fin("polygon.in");
	ofstream fout("polygon.out");

	fin>>n;
	for(int i=1;i<=n;i++) fin>>a[i];
	sort(a+1,a+n+1);

	for(int i=3;i<=n;i++)
		f(1,i);

	fout<<ans;
	fin.close();
	fout.close();
	return 0;
}
