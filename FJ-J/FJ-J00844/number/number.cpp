#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,f,g,h=0,i,j,k[1000004];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	a=s.size();
	for(i=0;i<a;i++){
		if(s[i]<='9'&&s[i]>='0'){
			h++;
			k[h]=s[i]-'0';
		}
	}
	sort(k+1,k+h+1);
	for(i=h;i>=1;i--){
		cout<<k[i];
	}
	return 0;
} 
