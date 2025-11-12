#include<bits/stdc++.h>
using namespace std;
int n,m,i,a[101],ai,an,am;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ai=a[1];
	sort(a+1,a+n*m+1);
	for(i=1;i<=n*m;i++){
		if(a[i]==ai){
			i=n*m-i+1;
			am=(i+n-1)/n;
			if(am%2==0){
				if(i%n==0){
					an=1;
				}else{
					an=n-(i%n)+1;
				}
			}else{
				if(i%n==0){
					an=n;
				}else{
					an=i%n;
				}
			}
			break;
		}
	}
	cout<<am<<" "<<an;
	return 0;
}
