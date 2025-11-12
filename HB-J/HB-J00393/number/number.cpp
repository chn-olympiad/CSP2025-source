#include<bits/stdc++.h>
using namespace std;
string nl;
int a[1000000],x=0,str;
int main(){
 	freopen("number.in","r",stdin);
 	freopen("number.out","w",stdout);
	cin>>nl;
	str=nl.length();
	for(int i=0;i<str;i++){
		if(nl[i]>='0'&&nl[i]<='9'){
			a[x]=nl[i]-'0';
			x++;
		}
	}
	sort(a,a+x);
	for(int i=x-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
