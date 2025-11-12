#include<bits/stdc++.h>
using namespace std;

string s;
int a[10];
long long l;

int main()
{
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio();
	cin.tie(0); cout.tie(0);
    cin >> s;
    l=s.size();
    for(int i=0; i<l; i++)
    {
		if(s[i]-'0'>=0 && s[i]-'0'<=9)
		{
			a[s[i]-'0']++;
		}
	}
	for(int i=9; i>=0; i--) 
	{
		while(a[i]--)
		{
			cout << i;
		}
	}
    return 0;
}
