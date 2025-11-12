#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("mumber.in","r",stdin);
	freopen("mumber.out","w",stdout);
	string s;
	cin>>s;
	int a[10010],c=0;
	for(int i=0;i<=s.size();i++){
		if(s[i]=='0'){
			a[c]=0;
			c++;
		}else if(s[i]=='1'){
			a[c]=1;
			c++;
		}else if(s[i]=='2'){
			a[c]=2;
			c++;
		}else if(s[i]=='3'){
			a[c]=3;
			c++;
		}else if(s[i]=='4'){
			a[c]=4;
			c++;
		}else if(s[i]=='5'){
			a[c]=5;
			c++;
		}else if(s[i]=='6'){
			a[c]=6;
			c++;
		}else if(s[i]=='7'){
			a[c]=7;
			c++;
		}else if(s[i]=='8'){
			a[c]=8;
			c++;
		}else if(s[i]=='9'){
			a[c]=9;
			c++;
		}
	}
	for(int i=0;i<=c-1;i++){
		for(int j=0;j<=c-1;j++){
			if(a[j]>a[i]){
				int f=a[j];
				a[j]=a[i];
				a[i]=f;
			}
		}
	}
	int m,b=1;
	for(int i=0;i<=c-1;i++){
		m+=a[i]*b;
		b=b*10;
	}
	cout<<m;
} 
