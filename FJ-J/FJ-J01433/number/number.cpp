#include<bits/stdc++.h>
using namespace std;
bool cmp(char q,char w){
	return q>w;
}
string s;
char a[1000001]; 
long long g=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout)£»
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			g++;
			a[g]=s[i];
		}
	}
	if(g==1){
		cout<<a[g];
		return 0;
	}
	sort(a+1,a+g+1,cmp);
	for(int i=1;i<=g;i++){
		if(a[i]==' '){
			continue;
		}
		cout<<a[i];	
	}
	return 0;
} 
