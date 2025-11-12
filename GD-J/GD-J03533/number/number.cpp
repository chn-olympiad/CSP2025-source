#include<bits/stdc++.h>
using namespace std;
char s[1000006];
int a[10]={0,0,0,0,0,0,0,0,0,0};
int cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;s[i]!=' ';i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			a[int(s[i])-48]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)printf("%d",i);
	}
    return 0;
}

