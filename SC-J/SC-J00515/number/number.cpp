#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
string s;
int n;
int a[maxn];
bool cmp(int xx,int yy){
	return xx>yy;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[++n]=s[i]-'0';
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	return 0;
}