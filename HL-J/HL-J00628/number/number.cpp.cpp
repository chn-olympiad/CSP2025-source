#include<bits/stdc++.h>
using namespace std;
long long c[1000001];
int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long a,size(),j=0;
	for(int i=0;i<=a;i++){
		if(s[i]>='1'&&s[i]<='9'){
			c[j]=int(s[i]);
			j++;
		}
	}
	for(int l=0;l<=j;l++)
	for(int i=1;i<j;i++){
		if(c[i=1]>c[i]){
			long long t;
			t=c[i+1];
			c[i+1]=c[i];
			c[i]=t;
		}
	}
	for(int i=1;i<=j;i++){
		cout<<c[i];
	}
	return 0;
} 
