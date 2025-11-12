#include<bits/stdc++.h>
using namespace std;
int n,m,k,a,num=1;
int l,h;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>k;
	for(int i=1;i<n*m;i++){
		cin>>a;
		if(a>k){
			num++;
		}
	}
	num%n==0?l=num/n:l=num/n+1;
	l%2==0?h=n-(num-(n*(l-1)))+1:h=num-(n*(l-1));
	cout<<l<<' '<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
