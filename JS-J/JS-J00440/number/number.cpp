#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],cnt=0;
string s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long unsigned int i=0;i<s.length();i++){
		if('0'<=s[i] && s[i]<='9'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(a,a+cnt,cmp);
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
	return 0;
}
