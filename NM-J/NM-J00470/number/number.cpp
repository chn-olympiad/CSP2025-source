#include<bits/stdc++.h>
using namespace std;
int a[1000],b=0,c;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<1000;i++){
		if(s[i]>='1'&&s[i]<='9'){
			a[i]=s[i];
			b++;
		}
	}
	for(int i=0;i<b;i++){
		for(int j=0;j<=b;j++){
			if(a[j]<a[j+1]){
				c=a[j];
				a[j]=a[j+1];
				a[j+1]=c;
			}
		}
	}

	for(int i=0;i<b;i++){
		cout<<a[i]-48;
	}
	return 0;
}
