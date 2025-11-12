#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],tot=0; 
bool cmp(int q,int w){
	return q>w;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[++tot]=s[i]-'0';
		}
	}
	sort(a+1,a+tot+1,cmp);
	for(int i=1;i<=tot;i++)cout<<a[i];
}
