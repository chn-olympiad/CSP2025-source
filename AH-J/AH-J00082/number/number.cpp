#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<string>
#include<queue>
using namespace std;
const int N=1e6+5;
int a[N],n=0;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;s[i];i++)
		if(s[i]>='0'&&s[i]<='9')
			a[++n]=s[i]-'0';
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--) cout<<a[i];
	cout<<"\n";
	return 0;
}

