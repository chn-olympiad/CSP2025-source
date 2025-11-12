#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[110],n,m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int R=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	int Rp=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			Rp=i;
		}
	}
	int Rm=ceil(Rp*1.0/n),Rn=0;
	if(Rm%2==1){
		if(Rp%n!=0){
			Rn=Rp%n;
		}
		else{
			Rn=n;
		}
	}
	else{
		Rn=n-Rp%n+1;
	}
	cout<<Rm<<" "<<Rn;
	return 0; 
}
