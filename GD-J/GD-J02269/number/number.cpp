#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
char s[N];
int a[N],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	
	cin>>s;	
	for (int i=0;i<strlen(s);i++)
		if(s[i]>='0' && s[i]<='9')
			a[++cnt]=s[i]-'0';
	sort(a+1,a+cnt+1);
	for (int i=cnt;i>=1;i--)	cout <<a[i];
}      
