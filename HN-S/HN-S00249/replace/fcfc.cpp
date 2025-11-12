#include<bits/stdc++.h>
typedef int int32;
#define int long long
using namespace std;
/*
	Author: wbw_121124
	ÈË½ÜµØÁé
	fcfc.cpp
*/
signed main()
{
	ifstream fin1("replace.out");
	ifstream fin2("replace3.ans");
	ofstream fout("aaaa.txt");
	string s,t;
	int cnt=0;
	while(fin1>>s)
	{
		cnt++;
		fin2>>t;
		if(s!=t)
			fout<<'#'<<cnt<<':'<<s<<':'<<t<<'\n';
	} 
	return 0;
}
