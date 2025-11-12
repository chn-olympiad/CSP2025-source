#include<bits/stdc++.h>
using namespace std;
const int N=1000000+100;
int a[N],top=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++top]=s[i]-'0';
		}
	}
	sort(a+1,a+1+top);
	for(int i=top;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}