#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int n[a.size()+5],g=0;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			g++;
			n[g]=a[i]-48;
		}
	}
	for(int i=1;i<=g;i++){
		int zd=INT_MIN,zdj=0;
		for(int j=1;j<=g;j++){
			if(n[j]>zd){
				zd=n[j];
				zdj=j;
			}
		}
		n[zdj]=-1;
		cout<<zd;
	}
	return 0;
}