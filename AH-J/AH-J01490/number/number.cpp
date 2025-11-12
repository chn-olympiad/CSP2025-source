# include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
int num[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for (int i = 0; i < s.size(); i++) if (isdigit(s[i])) num[++num[0]] = s[i] - '0';
	sort(num+1,num+1+num[0]);
	for (int i = num[0]; i >= 1; i--) printf("%d",num[i]);
	fclose(stdin);
	fclose(stdout);
}
