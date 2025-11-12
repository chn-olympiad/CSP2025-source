#include<bits/stdc++.h>
using namespace std;
int a[110];
bool check(int a,int b) {
	return a>=b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,pos;
	cin>>n>>m;
	for(int i=1; i<=n*m; i++)
		cin>>a[i];
	r=a[1];
	//for(int i=1; i<=n*m; i++)
	//	cout<<a[i]<<" ";
	//cout<<endl;
	sort(a+1,a+n*m+1,check);
	//for(int i=1; i<=n*m; i++)
	//	cout<<a[i]<<" ";
	//cout<<endl;
	for(int i=1; i<=n*m+1; i++) {
		if(a[i]==r) {
			pos=i;
			break;
		}
	}
	cout<<pos<<endl;
	int pn;
	if(pos%n!=0)
		pn=pos/n+1;
	else
		pn=pos/n;
	cout<<pn<<" ";
	if(pn%2==0)
		cout<<n-pos%n+1;
	else
		cout<<pos%n;
	return 0;
}
