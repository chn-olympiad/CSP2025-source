#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
string s,t;
int a[N];

int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
cin>>s;
int n=s.size();
for(int i=0;i<n;i++){
	if('0'<=s[i]&&s[i]<='9')t=t+s[i];
}
n=t.size();
for(int i=0;i<n;i++)a[i]=t[i]-'0';
sort(a,a+n);
for(int i=n-1;i>=0;i--)cout<<a[i];

return 0;
}
