#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,h=0,l=0,sum=0;
	cin>>n>>m;
	int a[105];
	int q=n*m;
	for(int i=1;i<=q;i++){
		cin>>a[i];
	}
	for(int i=1;i<=q;i++){
		if(a[i]>a[1]){
			sum++;
		}
	}
//	cout<<sum<<endl;
	l=sum/n+1;
	h=sum%m+1;
	cout<<l<<" "<<h;
	return 0;
}
