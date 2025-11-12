#include<bits/stdc++.h> 
using namespace std;
string s;
int a[1000006],p=1;
bool cmp(int a,int b){
	if(a==b){
		return 0;
	}
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[p]=(int)(s[i]-'0');
			p++;
		}
	}
	p--;
	sort(a+1,a+1+p,cmp);
	for(int i=1;i<=p;i++){
		cout<<a[i];
	}
	
	return 0;
}