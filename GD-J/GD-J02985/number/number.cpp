#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s[N];
int a[N],l,n;
bool c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>s;
	n=strlen(s);
	for(int i=0;i<n;i++)if(s[i]>='0'&&s[i]<='9')a[++l]=s[i]-'0';
	sort(a+1,a+1+l);
	for(int i=l;i;i--)cout<<a[i];
	return 0;
}
