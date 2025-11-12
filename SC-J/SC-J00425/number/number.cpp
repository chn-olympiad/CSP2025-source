#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int n=a.size();
	int b[n+1],j=0,s=0;
	for(int i=0;i<n;i++){
		if(int(a[i])<58){
			b[j]=a[i]-48;
			s++;
			j++;
		}
	}
	int c[s],ma=-1,d[s],w;
	for(int i=0;i<s;i++){
		c[i]=b[i];
	}
	for(int i=0;i<s;i++){
		ma=-1;
		for(int j=0;j<s;j++){
			if(c[j]>ma){
				ma=c[j];
				w=j;
			}
		}
		c[w]=0;
		d[i]=ma;
	}
	for(int i=0;i<s;i++){
		cout<<d[i];
	}
	return 0;
}