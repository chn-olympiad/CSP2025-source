#include <bits/stdc++.h> 
using namespace std;
string s;
long long l;
char x[500001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.length();i++)
	{
		if((s[i]<='9')&&(s[i]>='0')){
			x[l]=s[i];
			l++;
		}
	}
	sort(x,x+l);	
	for(int i=l-1;i>=0;i--)cout<<x[i];
	return 0;
}
