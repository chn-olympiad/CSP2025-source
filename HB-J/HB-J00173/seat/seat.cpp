#include <bits/stdc++.h>
using namespace std;
int n,m,a[1005],b;
int main()
{
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	cin>>n>>m;
	a[0]=101;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b=a[1];
	}
	for(int i=1;i<=n*m;i++){
		int c=i;
		while(a[c-1]<a[i]){
			int t=a[c-1];
			a[c-1]=a[c];
			a[c]=t;
			c--;
		}
	}
	for(int i=1;i<=m*n;i++){
		if(a[i]==b){
			int l=i/m;
			if(i%m!=0) l++;
			int h=i%(n*2);
			if(h>n) h=h-n+1;
			cout<<l<<" "<<h;
			return 0;
		}
	}
	return 0;
}
