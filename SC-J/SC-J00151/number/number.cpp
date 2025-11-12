#include<bits/stdc++.h>
using namespace std;
char s[10000000],a[10000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);     
	int m=1;
	for(int i=1;i<=1;i++){
		cin>>s[i];
		if(s[i]<='9' && s[i]>='0'){
			a[m]=s[i];
			m++; 
		}			
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m-i;j++){
			if(a[j]>a[j-1]){
				swap(a[j],a[j-1]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<a[i];
	}
	return 0;
}