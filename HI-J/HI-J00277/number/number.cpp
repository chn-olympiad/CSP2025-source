#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],j;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len = s.length();
	for(int i = 0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j] = s[i]-'0';
			j++;
		}
	}
	sort(a,a+j,cmp);
	for(int i = 0;i<j;i++){
		cout<<a[i];
	}
	return 0;
}

