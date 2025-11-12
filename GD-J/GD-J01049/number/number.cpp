#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//int x=0;
	string s,min;
	//double a[0];
	cin >> s;
	//for(int i=0;i<s.size();i++)
	//{
	//	if(s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9' || s[i] == '0')
	//	{
	//		a.add(s[i]);
	//		x+=1;
	//	}
	//}
	//a.sort();
	//for(int i=0;i<x;i++) cout << a[i];
	//cout << endl;
	string a1[s.size()];
	for(string i=0;i<s.size();i++)
	{
		min = 'a';
		for(string o=i;o<s.size()+1-i;o++)
		{
			if(s[o]<min) min = o;
		}
		a1[i] = min;
	}
	for(int i=0;i<s.size();i++) cout << ai[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
