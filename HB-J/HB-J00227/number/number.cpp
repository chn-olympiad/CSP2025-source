#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	int a[len+1]={0};
	int cnt=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
			cnt++;
		}
	}
	sort(a+0,a+len,cmp);
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
	return 0;
}
