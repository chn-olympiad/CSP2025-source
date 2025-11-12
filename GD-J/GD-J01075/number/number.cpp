#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
bool cmp(int a,int b){
	if(a>b) return true;
	else return false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int j=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[j++]=int(s[i]-'0');
	}
	sort(a+1,a+j,cmp);
	for(int i=1;i<j;i++){
		cout<<a[i];
	}
	return 0;
}  
