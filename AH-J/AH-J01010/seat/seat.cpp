#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[150];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	int sum=1;
	for (int i=2;i<=n*m;i++){
		cin>>a[i];
		if (a[i]>a[1])
			sum++;
	}
//	cout<<sum<<endl;
	int ansm=sum/n,ansn=sum%n;
	if (sum%n>0)
		ansm++;
	if (ansn==0)
		ansn=n;
	if (ansm%2==0)
		ansn=n-ansn+1;
	cout<<ansm<<" "<<ansn<<endl;
	return 0;
}


