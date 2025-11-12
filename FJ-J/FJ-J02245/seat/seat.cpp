#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int xh,xhxb;
	vector<int> a(n*m+1);
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xh=a[1];
	sort(a.begin()+1,a.end(),[](int a,int b){
		return a>b;
	});
	for(int i=1;i<=n*m;i++){
		//cout<<a[i]<<" ";
		if(a[i]==xh) xhxb=i;
	}
	//cout<<endl;
	int c=((xhxb-1)/n)+1,r;
	if((c-1)%2==0) r=xhxb-(c-1)*n;
	else r=c*n-xhxb+1;
	cout<<c<<" "<<r;
	return 0;
}
