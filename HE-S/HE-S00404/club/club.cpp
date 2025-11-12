#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n;
	cin>>n;
char a[2][n];
char b[2][n];
char c[2][n];
int a1=0;
int b1=0;
int c1=0;
	for(int i=1;i<=n;i++){
		cin>>a[2][i];
				cin>>b[2][i];
						cin>>c[2][i];
	if(a[0][i]>a[1][i]||a[0][i]>a[2][i])
	a1+=a[0][i];
		if(a[1][i]>a[0][i]||a[01][i]>a[2][i])
		a1+=a[1][i];
		if(a[2][i]>b[1][i]||a[2][i]>a[0][i])
		a1+=a[2][i];
	if(b[0][i]>b[1][i]||b[0][i]>b[2][i])
	b1+=b[0][i];
		if(b[1][i]>b[0][i]||b[01][i]>b[2][i])
		b1+=b[1][i];
		if(b[2][i]>b[1][i]||b[2][i]>b[0][i])
		b1+=b[2][i];		
	if(c[0][i]>c[1][i]||c[0][i]>c[2][i])
	c1+=c[0][i];
		if(c[1][i]>c[0][i]||c[01][i]>c[2][i])
		c1+=c[1][i];
		if(c[2][i]>c[1][i]||c[2][i]>c[0][i])
		c1+=c[2][i];		
	}
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c<<endl;
	return 0;
}
