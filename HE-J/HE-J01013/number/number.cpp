#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	for(int i=0;i<=s.size()-1;i++)
		if(s[i]-'0'>=0&&s[i]-'0'<=9)
			a[s[i]-'0']+=1;
	for(int i=9;i>=0;i--)
		while(a[i]>0){
			cout<<i;a[i]-=1;
		}
	return 0;
}
