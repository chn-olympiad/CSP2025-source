#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
string s;
int a[N],cnt;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++cnt]=s[i]-'0';
		}
	}
	bool flag=0;
	for(int i=1;i<=cnt;i++){
		if(a[i]!=0)flag=1;
	}
	if(!flag){
		cout<<0;
		return 0;
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
} 
