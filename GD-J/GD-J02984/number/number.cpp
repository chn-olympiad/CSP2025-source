#include<iostream>
#include<cstdio>
using namespace std;
string a;
int t[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9') t[int(a[i]-'0')]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=t[i];j++){
			cout<<i;//RP++
		}
	}
	return 0;
}
