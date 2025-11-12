#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int c=n*m;
	for(int i=1;i<=c;i++){
		cin>>a[i];
	}	
	int r=a[1],pos;
	sort(a+1,a+c+1);
	for(int i=c;i>=1;i--){
		if(r==a[i]){
			pos=c-i+1;
		}
	}
	int lie,hang;
	if(pos%n==0){
		lie=pos/n;
	}else{
		lie=pos/n+1;
	}
	if(lie%2!=0){
		if(pos%n==0){
			hang=n;
		}else{
			hang=pos%n;	
		}
	}else{
		if(pos%n==0){
			hang=n;
		}else{
			hang=n-pos%n+1;	
		}
	}
	cout<<lie<<" "<<hang;
	return 0;
}//4 4 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16