#include <bits/stdc++.h>
using namespace std;
int a[100010];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in",'w',stdin);
	freopen("number.out",'r',stdout);
	string s;
	bool l=0;
	int n=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n]=s[i]-'0';
			n++;
			if(a[i]>0){
				l=1;
			}
		}
	}
	if(l==0){
		cout<<0;
		return 0;	
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	return 0;
} 
