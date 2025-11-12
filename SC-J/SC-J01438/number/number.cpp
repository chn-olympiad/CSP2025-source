#include <bits./stdc++.h>
using namespace std;


int main(){
	string s;
	vector <int> n,m;
	int c;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	for (int i=0;i<s.size();i++){
		c=int(s[i])-48;
		if (c<10&&c>0-1)
		{
			n.push_back(c);
		}
	
	}
	
	
	for (int x=9;x>=0;x=x-1){
		for (int j=0;j<n.size();j++)
		{
			if (n[j]==x)
			{
				m.push_back(n[j]);
			}
		}
	}
	for (int y=0;y<m.size();y++)
	{
		cout << m[y];
	}
	return 0;
	
}