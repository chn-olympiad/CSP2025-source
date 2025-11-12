#include<bits/stdc++.h>
using namespace std;
int b[10000000],s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]-48<10&&a[i]-48>=0){
			s++;
			b[s]=a[i]-48;
		}
	}
	for(int i=1;i<=s;i++){
		for(int j=i;j<=s;j++){
			if(b[i]<b[j+1])swap(b[i],b[j+1]);
		}
	}
	for(int i=1;i<=s;i++)cout<<b[i];
	return 0;
}