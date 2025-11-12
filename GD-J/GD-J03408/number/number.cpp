#include<iostream>
#include<stdio.h>

using namespace std;

const int N=1e6,L=9;

char s[N+2];

int cnt[L+1];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	ios::sync_with_stdio(false); cin.tie(0),cout.tie(0);
	
	cin>>(s+1);
	
	for(int i=1;s[i];i++)
		if(s[i]>='0'&&s[i]<='9') cnt[s[i]^'0']++;
		
	for(int i=L;i>=0;i--)
		while(cnt[i]--) cout<<i;
	
	return 0;
}

