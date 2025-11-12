#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1010];
int b[1010][1010],r;
//int qz(int )
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int hm=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r)hm=i;//hm pai ming
		//cout<<hm<<endl;
	}
	int mr=ceil(double(hm)/double(n));
	int nr;
	if(mr%2==0){
		nr=(n-hm%n)%n+1;
	}else{
		if(hm%n==0)nr=n;
		else nr=hm%n;
		//cout<<"^";
	}
	cout<<mr<<" "<<nr;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			
//		}
//	}
	return 0;
}
