#include<bits/stdc++.h>
using namespace std;
int c[1000002];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int k=0,j=0;
	string s;
	cin>>s;
	while(1){
		if(s[j]=='\0') break; 
		if(s[j]>='0'&&s[j]<='9'){
			k++;
			c[k]=s[j]-'0';
		}
		j++;
	}
	sort(c+1,c+1+k);
	for(int i=k;i>=1;i--){
		cout<<c[i];
	}
	return 0;
} 