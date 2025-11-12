#include<bits/stdc++.h>
using namespace std;
string s;
int h=1,a[1000005];
bool cmd(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	int x=s.size();
	for(int i=0;i<=x;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[h]=s[i]-48;
			h++;
		}
	}
	sort(a+1,a+h+1,cmd);
	for(int i=1;i<h;i++){
		printf("%d",a[i]);
	}
	return 0;
}
