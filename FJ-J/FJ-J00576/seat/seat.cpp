#include<bits/stdc++.h>
using namespace std;
int n,m;//nĞĞ£¬mÁĞ¡£ 
int a[200];
int xiaor;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	xiaor=a[1];
	sort(a,a+1+n*m);
	int count=0;
	for(int i=n*m;i>=1;i--){
		count++;
		if(a[i]==xiaor){
			break;
		}
	}

	int lie=count/n,hang;
	if(count%n!=0){
		lie++;
	}
	
	
	if(lie%2==1){
		if(count%n!=0){
			hang=count%n;
		}
		else if(count%n==0){
			hang=n;
		}
	}
	else{
		hang=n-(count%n)+1;
	}
	cout << lie << " " << hang;
	return 0;
} 
