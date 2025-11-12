#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	int s[1000];
	cin>>s[1000];
	for(int i=0;i<10;i++){
		if(s[i]!=1||2||3||4||5||6||7||8||9||0){
			break;
		}
	}
	sort(s-1,s+1,cmp);
	cout<<s[1000];
	return 0;
}
