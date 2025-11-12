#include<bits/stdc++.h>//RP++
using namespace std;//RP++
int n,m,a[505],r;//RP++
int main(){//RP++
	freopen("seat.in","r",stdin);//RP++
	freopen("seat.out","w",stdout);//RP++
	cin>>n>>m;//RP++
	for(int i=1;i<=n*m;i++){//RP++
		cin>>a[i];//RP++
	}//RP++
	r=a[1];//RP++
	sort(a+1,a+n*m+1);//RP++
	int x=upper_bound(a+1,a+n*m+1,r)-a-1;//RP++
	x=n*m-x+1;//RP++
	int h=x/n;//RP++
	x%=n;//RP++
	if(x==0) x=n,h--;//RP++
	h++;//RP++
	if(h%2==0) x=m-x+1;//RP++
	cout<<h<<' '<<x;//RP++
	return 0;//RP++
} //RP++
