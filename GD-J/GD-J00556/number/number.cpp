#include<bits/stdc++.h>
using namespace std;
char a[1000009];
bool cmp(char x,char y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int cnt=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9' && s[i]>='0'){
			a[++cnt]=s[i];
		}
	}sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
} 
