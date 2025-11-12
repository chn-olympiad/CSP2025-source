#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
int len;
int leng=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[leng]=s[i]-'0';
			leng++;
		}
	}
	sort(a,a+leng,cmp);
	for(int i=0;i<leng;i++){
		cout<<a[i];
	}
	return 0;
}
