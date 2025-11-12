#include <bits/stdc++.h>
using namespace std;
int a[150];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i*m+j-m];
		}
	}
	sort(a+2,a+n*m+1,cmp);
	int t=0;
	for(int i=2;i<=n*m;i++){
		if(a[1]>a[i]){
			t=i-1;
			break;
		}
	}
	if(t==0){
		t=n*m;
	}
	//cout<<t<<"\n";
	int l=t/n;
	int h=t%n;
	if(h==0){
		h=n;
	}else{
		l++;
	} 
	if(l%2==1)
	cout<<l<<" "<<h;
	else{
		cout<<l<<" "<<n-h+1;
	}
	return 0;
}
