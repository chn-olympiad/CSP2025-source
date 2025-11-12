#include<bits/stdc++.h>
using namespace std;
string s;	
int a[1000001];
bool cmp(int c,int m){
	return (c>m);
}
void pinshu(int l){
	for(int j=1;j<=l;j++){
		if(l==1&&a[j]==0) {
			cout<<0;
			break;
		}
		else cout<<a[j];
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>s;
	int len=s.length(),num=0;
	for(int i=0;i<len;i++){
		if(s[i]<'a') {
			a[num+1]=s[i]-48;
			++num;
			
		}
	}
	sort(a+1,a+num+1,cmp);
	pinshu(num);
}