#include<bits/stdc++.h>
using namespace std;
string s;
int a[100005];
int n,d=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int z=0;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'>=0 and s[i]-'0'<=9){
			a[z]=s[i]-'0';
			z++;
		}
	}
	int y=0;
	for(int i=0;i<z;i++){
		int mi=a[i];
		for(int j=i;j<z;j++){
			if(a[j]<mi){
				int x=mi;
				mi=a[j];
				a[j]=x;
			}
		}
		a[i]=mi;
	}

	for(int i=0;i<z;i++){
		n+=a[i]*d;
		d*=10;
	}
	cout<<n;
	
	return 0;
}
