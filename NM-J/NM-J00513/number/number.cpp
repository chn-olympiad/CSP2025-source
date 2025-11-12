#include<bits/stdc++.h>
using namespace std;
long long a[1000004];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
	string s;
	cin>>s;
	long long sum=0,p=0;
	for(int i=0;i<s.size();i++){
		if(s[i]!='l'){
			if(s[i]>=0&&s[i]<='9'){
				a[p++]+=s[i]-48;
				s[i]='l';
			}
		}
	}
	sort(a,a+p,greater<int>());
	for(long long i=0;i<p;i++){
		cout<<a[i];
	}
	return 0;
}
