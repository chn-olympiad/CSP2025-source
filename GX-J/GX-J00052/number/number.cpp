#include <bits/stdc++.h>
using namespace std;
bool f(int x,int y){
	return x>=y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s="";
	cin>>s;
	int b=0,a[s.size()]={};
	for(int i=0;i<int(s.size());i++){
		if(s[i]>='0' && s[i]<='9'){
			a[b]=int(s[i]);
			b++;
		}
	}
	sort(a,a+s.size(),f);
	for(int i=0;i<b;i++){
	cout<<a[i];
	}
	return 0;
}
