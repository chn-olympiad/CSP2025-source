#include<bits/stdc++.h>
using namespace std;
string s1;
int b[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s1;
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9'){ 
			int p=s1[i]-'0';
			b[p]++;
		}
	}
	string s3="";
	int i=9;
	while(i>=0){
		while(b[i]>0){
			s3+=char(i+'0');
			b[i]--;
		}
		i--;
	}
	cout<<s3;
	return 0;
}
