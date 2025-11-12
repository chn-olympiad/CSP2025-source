#include<bits/stdc++.h>
using namespace std;
int a[10000003],s,t;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	int len=str.size();
	for(int i=0;i<len;i++){
		if('0'<=str[i]&&str[i]<='9'){
			a[t++]=str[i]-'0';
		}
	}
	sort(a,a+t,cmp);
	for(int i=0;i<t;i++) cout<<a[i];
	return 0;
}
/*
                        ^
                       |.|
                       |.|
                      -----
                        |
*/
