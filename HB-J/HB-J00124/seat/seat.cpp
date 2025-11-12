#include<bits/stdc++.h>
using namespace std;
long long n,m,Seats[150],Rm,Rn,lie,hang;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>Seats[i];
	Rm=Seats[1];
	sort(Seats+1,Seats+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(Seats[i]==Rm){
			Rn=n*m-i+1;
			break;
		}
	}
	if(Rn%n!=0){
		lie=Rn/n+1;
		if(lie%2==0) hang=n-(Rn%n)+1;
		else hang=(Rn%n);
	}
	else{
		lie=Rn/n;
		if(lie%2==0) hang=1;
		else hang=n;
	}
	cout<<lie<<' '<<hang;
	return 0;
}
