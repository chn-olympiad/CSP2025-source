#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],ans;
string str;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0'&&str[i]<='9'){
			a[++a[0]]=str[i]-'0';
		}
	}
	sort(a+1,a+1+a[0],cmp);
	for(int i=1;i<=a[0];i++){
		cout<<a[i];
	}
	return 0;
}
