#include<bits/stdc++.h>
using namespace std;
string s;
int a[15];
int fal=0,h4=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int g=0,u=s.size();
	for(int i=0;i<s.size()/2+1;i++){
		if(s[i]>='0' and s[i]<='9'){
			fal=s[i]-48;
			a[fal]++;
		}
		if(g!=u and s[u]>='0' and s[u]<='9'){
			fal=s[u]-48;
			a[fal]++;
		}
		if(g>=u){
			break;
		}else{
			g++;
			u--;
		}
		fal=0;
	}
	for(int i=9;i>=0;i--){
		if(a[i]==0){
			continue;
		}else{
			for(int j=1;j<=a[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
