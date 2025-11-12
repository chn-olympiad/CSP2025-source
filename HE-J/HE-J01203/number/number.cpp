#include<bits/stdc++.h>
using namespace std;
string s;
int b[1000009];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i=0;
	int j=1;
	while(cin>>s){
		i++;
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			b[j]=s[i];
			j++;
		}
	}
	sort(b[j],b[j]+1);
	for(int a=1;a<=j;a++){
		cout<<b[a];
	} 
	return 0; 
} 
