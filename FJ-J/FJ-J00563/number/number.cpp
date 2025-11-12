#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],m=0;
bool cnt(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i+1]=s[i]-48;
			m++;
		}
	}
	sort(a+1,a+s.size()+1,cnt);
	for(int i=1;i<=m;i++){
		cout<<a[i];
	}
	return 0;
}

