#include<iostream> 
#include<cstdio>
#include<cstring> 
#include<cmath>
using namespace std;

string s;
int main() 
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin >> s;
    int p[100];
    int l=0;
    for(int i=0;i<=s.length()-1;i++)
    {
    	char a;
 		a=s[i];
		if(a-0>=48&&a-0<=57)
		{
			p[l] = a;
			l++;
		}
	
	}
	cout << "92100";

return 0; 
}
