#include <bits/stdc++.h>

using namespace std;

int a[105]; 
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int b[15][15];
	int n,m;
	cin >> n >> m;
	int f=0;
	for(int i=0;i<n*m;i++){
		cin >> a[i];
	}
	f=a[0];
	sort(a,a+n*m,cmp);
	int t=0;
	for(int i=0;i<n*m;i++){
		if(a[i]!=f){
			t++;
		}
		if(a[i]==f){
			break;
		}
	}
	int p=(t+1)/n;
	int ans=(t+1)%n;
	int asn=0;
	if(ans!=0){
		asn=p+1;
	}
	else{
		asn=p;
	}
	if(asn%2==0){
		ans=n-ans;
	}
	if(ans==0){
		ans=n;
	}
	cout << asn <<" "<< ans;
	return 0;
}