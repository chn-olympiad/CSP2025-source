#include<bits/stdc++.h>
using namespace std;
int main()
{
	ifstream fin("replace.in");
	ofstream fout("replace.out");
	int n,q;
	fin>>n>>q;
	bool s1,s2;
	for(int i=1;i<=n;i++)fin>>s1>>s2;
	bool t1,t2;
	for(int i=1;i<=q;i++)fin>>t1>>t2;
	return 0;
}
