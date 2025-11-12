#include<bits/stdc++.h>
using namespace std;
string s;
int js,ans,a[1100100],b[1100100];
bool cmp(int x,int y){
	return x>y; 
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[++js]=int(s[i]-'0');
		}
	}
	sort(a+1,a+js+1,cmp);
	for(int i=1;i<=js;i++){
		cout<<a[i];
	}
}

