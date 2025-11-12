#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out ","w",stdout);
	int a[10000],b=0,d=0;
	string s;
    cin>>s;
	int j=s.length();
	for(int i=0;i<=j;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[b]=s[i]-'0';
			b++;
		}
	}
	for(int i=0;i<=b-1;i++){
		for(int j=i+1;j<b-1;j++){
		if(a[i]<a[j]){
			d=a[i];
			a[i]=a[j];
			a[j]=d;
		}}
	}
	for(int i=0;i<=b-1;i++){
		cout<<a[i];
	}
	return 0;
}
