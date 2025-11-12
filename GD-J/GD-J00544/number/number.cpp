#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
string s;
int n,a[N],len;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[++len]=s[i]-'0';
		}
	}
	sort(a+1,a+len+1);
	for(int i=len;i>=1;i--)	cout<<a[i];
	return 0;
}
//freopen("number.in","r",stdin);
/*
以后再也不用打J组了 >人< 
*/
