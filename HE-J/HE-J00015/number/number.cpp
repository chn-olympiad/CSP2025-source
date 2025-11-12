#include<bits/stdc++.h>
using namespace std;
string s;
char s1[1000006];
int x;
bool px(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]<='9'){
			s1[x++]=s[i]; 
		} 
	}
	sort(s1,s1+x,px);
	for(int i=0;i<=x;i++){
		cout<<s1[i];
	}
	return 0;
} 
