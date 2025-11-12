#include<bits/stdc++.h>
using namespace std;
string s;
long long  a[1000010];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s;
	long long j=0;
	for(int i=0;i<s.length();i++){
		if(0<=s[i]-'0'&&s[i]-'0'<=9){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a,a+j,cmp);
	for(int i=0;i<j;i++){
		cout<<a[i];
	}
}