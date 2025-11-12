#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],ai;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	cin>>s;
	int sl=s.length();
	for(int i=0;i<sl;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[ai]=s[i]-'0',ai++;
		}
	}
	sort(a,a+ai);
	for(int i=ai-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
