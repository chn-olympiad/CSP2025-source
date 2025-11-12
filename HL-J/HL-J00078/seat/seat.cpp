#include<bits/stdc++.h>
using namespace std;
int a1,n,m;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a1=a[1];
	int id1;
	for(int i=1;i<=n*m;i++){
		if(a[i]<a[i+1]){
			swap(a[i],a[i+1]);
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			id1=i;
			break;	
		}
	}
	int ansn,ansm;
	if(id1<=n){
		cout<<1<<' '<<id1;
		return 0;
	}
	else{
		if(id1%n==0){
			ansm=id1/n;
			if(ansm%2==0){
				ansn=1;
			}
			else{
				ansn=n;
			}
			cout<<ansm<<' '<<ansn;
			return 0;
		}
		else{
			ansm=(id1/n)+1;
			if(ansm%2==0){
				ansn=n-(id1%n)+1;
			}
			else{
				ansn=id1%n;
			}
			cout<<ansm<<' '<<ansn;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
