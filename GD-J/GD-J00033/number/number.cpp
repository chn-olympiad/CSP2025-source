#include<bits/stdc++.h>
using namespace std;
int m=0;
int lis[1000000];
void px(){
	for(int i=0;i<m*3355033;i++){
		int a=0;
		for(int j=i;j<=m-i;j++){
			while(lis[i]<lis[j]){
				a=lis[i];lis[i]=lis[j];lis[j]=a;
			}
		}
	}
}
int main(){
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(isdigit(s[i])){
			lis[m]=s[i]-'0';
			m++;
		}
	}
	px();
	for(int i=0;i<m;i++){
		cout<<lis[i];
	}
	return 0;	
}
