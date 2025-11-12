#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],js;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int ls=s.size();
	for(int i=0;i<ls;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i+1]=s[i]-'0';
			js++;
		}
	}
	sort(a+1,a+ls+1,cmp);
	for(int i=1;i<=js;i++) cout<<a[i];
	return 0;
}
