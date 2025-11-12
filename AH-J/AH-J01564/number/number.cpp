#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int main(){//T1 2025/11/01 09:07:33 passed.(100 pts)
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);

	char c;
	int t=0;
	while(cin>>c)
		if(isdigit(c))s[t]=c,t++;
		
	sort(s,s+t);
	for(int i=t;i>=0;i--)cout<<s[i];
	return 0;
}
/*
	 * WO YAO SHANG MI HUO XING WEI DA SHANG !!
	 * I love furina forever!! 
	 * I love huahuo forever!!
	 * (bool ys=false,bt=false)
*/
