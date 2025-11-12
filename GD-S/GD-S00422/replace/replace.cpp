#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int n,q;

string s1[200000];
string s2[200000];
string as1[200000];
string as2[200000];
int ans[200000];
string cx,cy;
int IsSub(string m,string t)
{
	int ok = 0;
	int ms = m.size();
	int ts = t.size();
	for(int i =0; i < ms;i++)
	{
		cx = "";
		cy = "";
		ok = 1;
		for(int j = 0; j < ts;j++)
		{
			if(i +j >= ms)
			{
				if(ok == 0)
				break;
				if(j +1 < ts)
				{
					//no
					ok = 0;
					break;
				}
				break;
			}
			if(m[i+j] != t[j])
				{
					ok = 0;
					//i+=j>>2;
					break;
				}
		}
		if(ok)
		{
			for(int ci =0;ci <i;ci++)
			cx += m[ci];
			for(int ce = ts + i;ce < ms;ce++)
			cy += m[ce];
			return 1;
		}
	}
	return 0;
}
string Grp(int ind)
{
	string c = cx + s2[ind] + cy;
	return c;
}
int Same(string s1,string s2)
{
	if(strcmp(s1.c_str(),s2.c_str()))
	return 0;
	return 1;
}
int main()
{
	ifstream fi("replace.in");
	ofstream fo("replace.out");
	
	fi >> n >> q;
	
	for(int i = 0; i < n; i ++)
	{
		fi >> s1[i] >> s2[i];
	}
	string t1,t2;
	for(int a = 0; a < q;a++)
	{
		//ask
		fi >> t1 >> t2;
		as1[a] = t1;
		as2[a] = t2;
		for(int i = 0; i < n; i ++)
	{
		if(IsSub(as1[a],s1[i]))
			{
				
				string vcc = Grp(i);
				//cout << "is sub!! and if is same s1:" << vcc << " |||s2:" << as2[a]<<endl;
				if(Same(vcc,as2[a]))
				{
					//cout << "is same!!!" << endl;
					ans[a]++;
				}
			}
	}
	fo << ans[a];
		if(a +1 < q)
			fo << endl;
	}
	return 0;
}
