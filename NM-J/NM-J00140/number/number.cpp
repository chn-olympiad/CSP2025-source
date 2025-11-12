#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N],k=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int ss=s.size();
	for(int i=0;i<ss;i++){
		if(s[i]>='0'&&s[i]<='9')a[++k]=s[i]-'0';
	}
	sort(a+1,a+k+1,greater<int>());
	for(int i=1;i<=k;i++)cout<<a[i];
	return 0;
}
