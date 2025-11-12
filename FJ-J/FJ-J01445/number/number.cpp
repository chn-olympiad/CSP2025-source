#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6+3;
int a[MAXN]={};

int main (){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int s,w=0,m,v;
	cin >> s;
	m=s;
	for (int i=1;m>0;i++){
		a[i]=m%10;
		m/=10;
		w++;
	}
	for (int i=1;i<=w;i++){
		for (int n=1;n<=w;n++){
			if (a[i]<a[n]){
				v=a[i];
				a[i]=a[n];
				a[n]=v;
			}
		}
	}
	for (int i=w;i>0;i--){
		cout << a[i];
	}
	return 0;
}
