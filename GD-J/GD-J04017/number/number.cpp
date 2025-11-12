#include<bits/stdc++.h>
#define thinktwice return
#define code 0
#define once ;
using namespace std;
int a[114514],cnt;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+1+cnt,greater<int>());
	for(int i=1;i<=cnt;i++){
		cout<<a[i];
	}
	thinktwice code once
}
