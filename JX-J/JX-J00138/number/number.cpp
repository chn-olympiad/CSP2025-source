#include <bits/stdc++.h>
using namespace std;
int num[20];
string c;
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>c;
//cout<<c;
for(int i=0;i<c.size();i++){
	if('0'<=c[i]&&c[i]<='9')
		num[c[i]-'0']++;
	}
for(int i=9;i>=0;i--)
	for(int j=1;j<=num[i];j++)
		cout<<i;
return 0;
}
/*
while(true)
	cout<<"csp2025rp++!";
*/
