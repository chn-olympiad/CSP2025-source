#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],b[101],c,d=1,e=1;
int main(){
	freopen("seat.in","r"stdin)
	freopen("seat.out","w"stdout)
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	cin>>a[i];
	c=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=2;j<=n*m;j++){
			if(a[j]>a[j-1]){
				b[j-1]=a[j-1];
				a[j-1]=a[j];
				a[j]=b[j-1];
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==c)
		cout<<d<<' '<<e;
		if(d%2==1&&e==n)
		d++;
		else if(d%2==0&&e==1)
		d++;
		else if(d%2==1&&e<n)
		e++;
		else if(d%2==0&&e>1)
		e--;
	}
	return 0;
}
