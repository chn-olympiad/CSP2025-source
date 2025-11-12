#include<bits/stdc++.h>
using namespace std;
//#Shang4Shan3Ruo6Shui4
string a;
long long f[110];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	long long l=a.size();
	for(int i=0;i<l;i++)
	{
		if(a[i]<='9'&&a[i]>='0') f[int(a[i]-'0')]++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=f[i];j++) cout<<i;
	}
	return 0;
} 
