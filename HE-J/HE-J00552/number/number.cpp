#include<bits/stdc++.h>
using namespace std;
string s;
int tong[10];
int main(){
	
	//一定要记得取消注释 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')tong[s[i]-48]+=1;
	}
	
	for(int i=9;i>=0;i--){
		while(tong[i]!=0){
			printf("%d",i);tong[i]-=1;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
