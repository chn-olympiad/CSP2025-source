#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[N]={0},f=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[f]=int(s[i]-48);
			f++;
		}
	}
	sort(a+1,a+f,cmp);
	for(int i=1;i<f;i++) cout<<a[i];
	return 0;
}
//freopen记得去注释 
//为啥不输入啊??? 
//哎呦我真服了算了保龄就保龄吧 
