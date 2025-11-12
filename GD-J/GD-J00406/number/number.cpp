#include<bits/stdc++.h>
using namespace std;
int a[20]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if((s[i]-'0')>10){
			
		}else{
			a[s[i]-'0']++;
		}
	}
	for(int i=10;i>=0;i--){
		while(a[i]>0){
			printf("%d",i); 
			a[i]--;
		}
	}
} 
