#include<bits/stdc++.h>
using namespace std;
int num[1003];
int vis[1003]={0};
char s[100005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=strlen(s),m=0;
	for(int i=0;i<l;i++){
		if(0<=s[i]-'0' && s[i]-'0'<=9){
			num[m]=s[i]-'0';
			m++;
		} 
	}
	int Max=9;
	while(Max>=0){
		for(int i=0;i<m;i++){
			if(num[i]==Max && !vis[i]){
				cout<<Max;	
				vis[i]=1;
			} 
		}
		Max--;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}