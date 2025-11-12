#include<bits/stdc++.h>
using namespace std;
string str;
int k,a[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>str;
	for(int i=0;i<str.size();i++)if(isdigit(str[i]))a[k++]=str[i]^48;
	sort(a,a+k);
	for(int i=k-1;i>=0;i--)cout<<a[i];
	return 0;
}
