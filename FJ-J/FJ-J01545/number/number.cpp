#include<bits/stdc++.h>
using namespace std;
int a[1000005],t=0;
string s;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<'a'){
			a[t]=s[i];
			t++;
		}
	}
	
	sort(a,a+t,cmp);
	for(int i=0;i<t;i++) cout<<a[i]-48;
	return 0;
}


