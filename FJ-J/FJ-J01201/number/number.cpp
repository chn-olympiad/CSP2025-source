# include <bits/stdc++.h>
# define N 1000010
using namespace std;
char s[N];
int p[200],n;
int main() {
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin>>s,n=strlen(s); 
	for(int i=0;i<n;i++) 
	  if(s[i]>='0'&&s[i]<='9')
	    p[s[i]-'0']++;
	for(int i=9;i>=0;i--)
	  while(p[i]) cout<<i,p[i]--;
	return 0;
}
