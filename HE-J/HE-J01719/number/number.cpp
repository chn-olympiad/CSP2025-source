#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
string s;
char a[maxn];
int res[maxn];
int cnt=0;
bool cmp(int a,int b){
	if(a!=b){
		return a>b;
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=1;i<=maxn;i++){
		res[i]=-1;
	}
	for(int i=0;i<=s.size()-1;i++){
		a[i+1]=s[i];
	}
	for(int i=1;i<=s.size();i++){
		if(a[i]-'0'>=0&&a[i]-'0'<=9){
//			cout<<a[i]-'0';
			res[i]=a[i]-'0';
			cnt++;
		}
	}
	sort(res+1,res+cnt+1,cmp);
	for(int i=1;i<=maxn;i++){
		if(res[i]==-1){
			continue;
		}
		cout<<res[i];
	}
	return 0;
}

