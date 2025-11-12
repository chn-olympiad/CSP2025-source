#include<bits/stdc++.h>
using namespace std;
int k;
char e[1000066];
string s;
int cmp(int a,int b){
	return a>b;
} 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			k++;
			e[k]=s[i];
		}
	}
	sort(e+1,e+k+1,cmp);
	for(int i=1;i<=k;i++)cout<<e[i];
	return 0;
}
