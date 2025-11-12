#include<bits/stdc++.h>
using namespace std;
int b[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int j=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			b[j]=s[i]-'0';
			j+=1;
		}
	}
	sort(b,b+j);
	for(int i=j-1;i>=0;i--){
		cout<<b[i];
	}
	cout<<endl;
	return 0;
} 
