#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[120],b[12][12];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
			cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			int h=i/n+1,l;
			if(h%2)l=i%n;
			else l=n-i%n+1;
			cout<<h<<' '<<l;
			break;
		}
	}
	return 0;
} 

