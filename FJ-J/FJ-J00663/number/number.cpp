#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000010],p=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[p++]=s[i]-'0';
		}
	}
	sort(num,num+p,cmp);
	for(int i=0;i<p;i++){
		cout<<num[i];
	}
	return 0;
}
