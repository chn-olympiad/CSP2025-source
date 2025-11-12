#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","W",stdout);
	string s;
	cin>>s;
	int a[s.size()+5];
	int v=0;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9' && s[i]>='0'){
			v++;
			a[v]=s[i]-'0';
		}
	}
	sort(a+1,a+v+1,cmp);
	for(int i=1;i<=v;i++){
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}
