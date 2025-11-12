#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int a,int b){
	return a>b;
}	
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size(),n=0;
	for(int i=0;i<l;i++){
		int kp=s[i]-'0';
		if(kp>=0&&kp<=9){
			a[n++]=kp;
		}	
	}	
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		cout<<a[i];
	}	
	return 0;
}
