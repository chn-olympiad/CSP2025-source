#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000010
string s;
int a[MAXN],top;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++top]=s[i]-'0';
		}
	}
	sort(a+1,a+top+1,greater<int>());
	bool flag=false;
	if(a[1]==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=top;i++){
		cout<<a[i];
	}
	return 0;
} 
