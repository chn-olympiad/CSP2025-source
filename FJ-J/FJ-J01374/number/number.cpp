#include<bits/stdc++.h>
using namespace std;
int a[1000005];
string s;
int len;
int nm=0;
bool cmp(int x,int y){
	return x>=y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i+1]=s[i]-'0';
			nm++;
		}
	}
	sort(a+1,a+1+len,cmp);
	for(int i=1;i<=nm;i++){
		cout<<a[i];
	}
	
	
	return 0;
}
