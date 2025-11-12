#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000010],j,l;
bool cmp(int x,int y){
	return  x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a+0,a+l,cmp);
	for(int i=0;i<j;i++){
		cout<<a[i];
	}
	return 0;
}
