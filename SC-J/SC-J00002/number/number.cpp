#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;
string s;
int tmp=0,a[N]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if((s[i]-'0')>=0&&(s[i]-'0')<=9){
			a[tmp]=s[i]-'0'; 
			tmp++;
		}
	}
	sort(a,a+tmp);
	for(int i=tmp-1;i>=0;i--){
		printf("%d",a[i]);
	}
	
	return 0;
} 
