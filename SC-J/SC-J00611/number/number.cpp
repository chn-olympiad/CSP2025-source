#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
bool ans(int x,int y){
	return x>y;
}
int main(){
	cin>>s;
	int len=s.size();
	int x=1;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[x]=s[i]-'0';
			x++;
		}
	}
	sort(a+1,a+x,ans);
	for(int i=1;i<x;i++){
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}
 