#include<bits/stdc++.h>
using namespace std;
string s;
char c[1010],p='0';
int b=0;
int a[1010];
bool cnt(char a,char b){
	return a>b;
}
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	cin>>s;
	if(s.size()==1) cout<<s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			c[i]=s[i];
			b++;
		}
	}
	sort(c,c+b,cnt);
	for(int i=0;i<b;i++){
		cout<<c[i];
	}
	return 0;
} 
