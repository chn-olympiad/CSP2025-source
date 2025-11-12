#include<bits/stdc++.h>
using namespace std;
int a[114514];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",std.in);
	freopen("number.out","w",std.out);
	string s;
	cin>>s;
	int len=s.size();
	int n=1;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n]=s[i]-'0';
			n++;
		}
	}
	sort(a,a+len+1,cmp);
	for(int i=0;i<n-1;i++){
		cout<<a[i];
	}
	return 0;
}
