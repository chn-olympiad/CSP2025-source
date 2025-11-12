#include<bits/stdc++.h>
using namespace std;
int cn(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int cnt=0,a[100000];
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(a,a+cnt,cn);
	if(a[0]==0){
		cout<<0;
		return 0;
	}
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
	return 0;
} 