#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
}

const int N=1e3+5;
int a[N];
int main(void){

	freopen("seat.in ","r",stdin);
	freopen("seat.out ","w",stdout);
	


	
	int n,m;
	cin>>n>>m;
     int ans;
	for(int i=1; i<=n*m; i++){
	cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+n*m,cmp);
	for(int i=1; i<=n*m; i++){
		if(a[i]==ans){
			ans=i;
		break;
		}
	}

	int ansl=(ans+m-1)/m;
	

	int ansh=ans%m;
	if(ansh==0){
		ansh=m;
	}
	if(ansl%2==1){
		
		cout<<ansl<<" "<<ansh;
	}
	else{
		cout<<ansl<<" "<<m-ansh+1;
	}
	
	return 0;
}



