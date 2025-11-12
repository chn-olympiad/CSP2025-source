#include<bits/stdc++.h>
using namespace std;

string s;
int c[(int)1e6+10];
char input;

int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
//	cin>>s;
	int pos = 0;
//	for(int i=1;i<=s.length();i+=1){
//		if(s[i]>='0' and s[i]<='9'){
//			c[++pos] = s[i];
//		}
//	}
//	sort(c+1,c+pos);
//	for(int i=pos;i>=1;i+=1){
//		cout<<c[i];
//	}
	
	cin>>s;
	for(int i=0;i<s.size();i+=1){
		if(s[i]>='0' and s[i]<='9'){
			c[++pos] = s[i]-'0';
		}
	}
	sort(c+1,c+1+pos);
	for(int i=pos;i>=1;i-=1){
		cout<<c[i];
	}
	
	return 0;
	
}
