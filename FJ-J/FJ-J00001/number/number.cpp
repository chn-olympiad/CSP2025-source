#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int a[1000005];
int book[1000005];
int cmp(int a,int b){
	return a>b;
}
int main(){
		ios::sync_with_stdio(0);
//		freopen("number.in","r",stdin);
//		freopen("number.out","w",stdout);
		cin>>s;
		for(int i=0;i<s.size();i++){
			if(s[i]>='0' && s[i]<='9'){
				a[n]=s[i]-'0';
				book[n]=1;
				n++;
			} 
		}
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++){
			if(book[i]){
				 cout<<a[i];  
			}
	}
	return 0;
}
