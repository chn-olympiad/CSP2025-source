#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
int b[11]={0};
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]-'0'>=0&&a[i]-'0'<=9)b[a[i]-'0']++; 
	}
	for(int i=9;i>=0;i--){
		for(int o=0;o<b[i];o++){
			cout<<i; 
		}
	}
	return 0;
}
