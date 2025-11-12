#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int a[N];
bool cmp(int c,int d){
	return c>d; 
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(a,0,sizeof(a));
	string s;
	cin>>s;
	int len=0;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[len]=(s[i]-'0');
			len++;
		}
	}
	if(s.length()==1){
		cout<<s;
		return 0;
	}
	sort(a,a+len,cmp);
	for(int i=0;i<len;i++)cout<<a[i];
	return 0;
} 
