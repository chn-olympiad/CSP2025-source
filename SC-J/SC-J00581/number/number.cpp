#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char a[100];
	int b=0;
	cin>>s;
	int k=s.length(),m;
	if(k>1000000){
		return 0;
	}
	for(int i=0;i<k;i++){
		if(s[i]>='1'&&s[i]<='9'){
			a[b]=s[i];
			b++;
		}
	}
	for(int i=0;i<=b;i++){
		for(int j=0;j<=b+1;j++){
			if(a[j]>a[j+1]){
				m=a[j+1];
				a[j+1]=a[j];
				a[j]=m;
			}
		}
	}
	for(int i=b+1;i>=0;i--){
		cout<<a[i];
	}
	
}