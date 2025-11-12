#include <bits/stdc++.h>
using namespace std;
const int maxn=1e8;
int a[maxn]={};
void pop(int len){
	for (int j=len;j>1;j--){
		for (int i=0;i<j-1;i++){
			if(a[i]<a[i+1]){
				swap(a[i],a[i+1]);
			}
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int k=0;
	for (int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a[k++]=s[i]-'0';
		}
	}
	pop(k);
	for(int i=0;i<k;i++){
		cout<<a[i];
	}
	return 0;
}