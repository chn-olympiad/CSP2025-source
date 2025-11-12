#include<bits/stdc++.h>
using namespace std;

bool cmt(int a,int b){
	return a>b;
}
string s;
int l,k=1,a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]-'a'<0){
			a[k]=s[i]-'0';
			k++;
		}
	}
	sort(a+1,a+k,cmt);
	for(int i=1;i<k;i++){
		cout<<a[i];
	}
	return 0;
}