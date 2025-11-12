#include <bits/stdc++.h>
using namespace std;
int a[200],n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int fr=a[1],hr;
	sort(a+1,a+1+m*n,cmp);
	for(int i=1;i<=n*m;i++)
		if(fr==a[i]){hr=i;break;}
	int l,h;
	l=hr/n+bool(hr%n);
	if(l%2){
		if(hr%n) h=hr%n;
		else h=n;
	}
	else{
		if(hr%n) h=n-(hr%n)+1;
		else h=1;
	}
	cout<<l<<" "<<h;
    return 0;
}
