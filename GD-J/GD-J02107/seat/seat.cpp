#include<bits/stdc++.h>
using namespace std;
int r;
int a[15*15];
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	r=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++){
		for(int j=1+i;j<=n*m;j++){
			if(a[i]<a[j])swap(a[i],a[j]);
		}
	} 
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			r=i;
			break;
		}
	}
	int rr=r,N=n,M=m;
	int x=(r/n),y;
	if(r%n!=0)x++;
	int rm=rr%m;
	if(x%2==0){
		y=N-rm+1;
	}
	else y=rm;
	if(rm==0)y=n;
	cout<<x<<" "<<y;
	return 0;
}

