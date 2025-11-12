#include<bits/stdc++.h>
using namespace std;
string s;
int cnt=1,a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	frepoen("number.in","r"stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt-1;i++){
		if(a[i]!=a[i-1]){
			cout<<a[i];
		}	
	}
	return 0;
}
