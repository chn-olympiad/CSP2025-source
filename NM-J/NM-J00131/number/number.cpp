#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1001],a[1001];
	for(int i=1;i<=s.lenth();i++){
		cin>>s[i];
		if(s[i]>=1 && s[i]<=10){
			a[i]=s[i];
			if(a[i]>a[i-1]){
				a[i-1]=a[i];
			}
		}
	}
	cout<<a;
	
	
	return 0;
}
