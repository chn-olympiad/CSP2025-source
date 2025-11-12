#include<bits/stdc++.h>
using namespace std;
string s;
const int N=1e6+5;
int a[N],k;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]<='9'&&s[i]>='0'){
			a[++k]=(s[i]-'0');
		}
	}
	sort(a+1,a+1+k,cmp);
	for(int i=1;i<=k;++i){
		cout<<a[i];
	}
	return 0;
}
