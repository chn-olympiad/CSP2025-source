#include <bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;
int a[maxn];
bool isnumber(char c){
	if (c>='0' &&  c<='9') return true;
	else return false;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=0;
	for (int i=0;i<s.length();i++){
		char c=s[i];
		if (isnumber(c)){
			len++;
			a[len] = (int) c-48;
		}else{
			continue;
		}
	}
	sort (a+1,a+len+1,cmp);
	for (int i=1;i<=len;i++){
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}
