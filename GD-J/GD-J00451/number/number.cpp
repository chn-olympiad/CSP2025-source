#include<bits/stdc++.h>
using namespace std;
char s[1145141];
int a[114];
int flag;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.getline(s,1145141);
	int x=strlen(s);
	for(int i=0;i<=x;i++){
		if('0'<=s[i]&&'9'>=s[i]){
			a[s[i]-'0']++;
			if(s[i]-'0'!=0){
				flag=1;
			}
		}
	}
	if(flag==1){
		for(int i=9;i>=0;i--){
			for(int j=1;j<=a[i];j++){
				cout<<i;
			}
		}		
	}
	else{
		cout<<0;
	}
	return 0;
} 
