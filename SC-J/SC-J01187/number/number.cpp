#include<bits/stdc++.h>
using namespace std;
int a[1000001],cnt,b;
int main(){
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		int k=s[i]-'0';
		if((k<=9)&&(k>=0)){
			a[cnt++]=k;
		}
	}
	sort(a,a+cnt);
	for(int i=cnt-1;i>=0;i--){
		b=b*10+a[i];
	}
	cout<<b;
	return 0;
} 