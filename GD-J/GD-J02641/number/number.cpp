#include<bits/stdc++.h>
using namespace std;
char s[1000006]; 
int a[1000006];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[s[i]-'0']++; 
		} 
	} 
	for(int i=9;i>=0;i--){
		if(a[i])
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}//cout<<endl;
	return 0;
}
