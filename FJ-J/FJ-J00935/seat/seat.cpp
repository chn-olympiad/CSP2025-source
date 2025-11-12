#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],a1,k,s,l,x=0,y=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	a1=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			k=i;
			break;
		}
	}
	if(k%(2*n)!=0) l=k/(2*n)+1;
	else l=k/(2*n);
	x+=(l-1)*2;
	k-=(l-1)*2*n;
	if(k<=n){
		x++;
		y=k;
	}
	else{
		x+=2;
		y=1+2*n-k;
	}
	cout<<x<<' '<<y;
	fclose(stdin);fclose(stdout);
	return 0;
}
