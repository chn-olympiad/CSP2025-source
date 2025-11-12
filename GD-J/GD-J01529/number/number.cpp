#include<bits/stdc++.h>
using namespace std;
string s;
const int maxn=1e6+10;
int sum=0,x=0,a[maxn];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>47&&s[i]<58){
			a[++x]=s[i]-48;
		}
	}
	sort(a+1,a+x+1);
	for(int i=x;i>=1;i--){
		printf("%d",a[i]);
	}
	return 0;
}
