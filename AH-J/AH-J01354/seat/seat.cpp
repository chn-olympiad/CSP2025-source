#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10010],b[10010],cnt,h,l,t,te;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b,b+n*m);
	for(int i=n*m-1;i>=0;i--){
		if(b[i]==a[0]){
			cnt=n*m-i;
			break;
		}
	}
	l=cnt/n;
	if(cnt%n) l++;
	t=l*n;
	for(;;){
		te++;
		if(t==cnt)break;
		t--;
	}
	if(l%2) h=n-te+1;
	else h=te;
	cout<<l<<" "<<h;
	return 0;
}
