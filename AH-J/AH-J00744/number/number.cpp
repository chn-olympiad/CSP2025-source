#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],t=1;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int h=s.size();
	for(int i=0;i<h;i++){
		if(s[i]>=48&&s[i]<=57){
			a[t]=s[i]-48;
			t++;
		}
	}
	sort(a+1,a+t,cmp);
	for(int i=1;i<t;i++) cout<<a[i];
	return 0;
}
