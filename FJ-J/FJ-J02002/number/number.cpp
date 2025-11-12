#include<bits/stdc++.h>

using namespace std;
int c[1000005],idx=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i = 0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			c[++idx]=s[i]-'0';
		}
	}
	sort(c+1,c+idx+1,cmp);
	for(int i = 1;i<=idx;i++){
		cout<<c[i];
	}
	return 0;
}
