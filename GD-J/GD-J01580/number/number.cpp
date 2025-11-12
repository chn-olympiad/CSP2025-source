#include<bits/stdc++.h>
using namespace std;
string s;
const int N=1000010;
int t=0;
int a[N];
int b;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.length();i++){
		if(s[i]>='0' and s[i]<='9'){
			a[t]=s[i];
			t++;
		}
	}
	for(int i=0;i<=t-1;i++){
		for(int j=0;j<=t-1;j++){
			if(a[j]<a[j+1]){
				b=a[j+1];
				a[j+1]=a[j];
				a[j]=b;
			} 	
		}
	}
	for(int i=0;i<=t-1;i++){
		cout<<a[i]-48;
	}
	
	
	
	return 0;
}
