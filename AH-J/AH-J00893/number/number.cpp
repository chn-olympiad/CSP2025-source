#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int cnt=0;
int main(){
freopen ("number.in","r",stdin);
freopen ("number.out","w",stdout);
ios::sync_with_stdio(0);
string s;
cin>>s;

for (long unsigned int i=0;i<s.size();i++){
	if (s[i]>='0' && s[i]<='9')a[++cnt]=s[i]-'0';
}
    sort (a+1,a+cnt+1);
    for (int i=cnt;i>=1;i--)cout<<a[i];
    cout<<endl;
	return 0;
}
