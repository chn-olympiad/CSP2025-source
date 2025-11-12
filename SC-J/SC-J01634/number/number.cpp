#include <bits/stdc++.h>
using namespace std;
string s;
bool jl[1000050];
int l,p[1000050],ll;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]-48<=9){
			jl[i]=1;
		}
	}
	for(int i=0;i<l;i++){
		if(jl[i]==1){
			ll++;
			p[ll]=s[i]-48;
		}
	}
	sort(p+1,p+1+ll);
	for(int i=ll;i>=1;i--){
		cout<<p[i];
	}
	
	return 0;
}