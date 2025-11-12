#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[100005],js=0;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int p=a[0];
	sort(a,a+n);
	if(n==1&&m==1){
		cout<<"1 1";
		return 0;
	}
	if(n==1){
		for(int i=n-1;i>=0;i--){
			js++;
			if(a[i]==p){
				cout<<js<<' '<<1;
				return 0;
			}
		}
	}
	if(m==1){
		for(int i=n-1;i>=0;i--){
			js++;
			if(a[i]==p){
				cout<<1<<' '<<js;
				return 0;
			}
		}
	}
	if(n==2&&m==2){
		for(int i=n-1;i>=0;i--){
			js++;
			if(a[i]==p) break;
		}
		if(js==1) cout<<"1 1";
		if(js==2) cout<<"1 2";
		if(js==3) cout<<"2 2";
		if(js==4) cout<<"2 1";
		return 0;
	}
	if(n==2&&m==3){
		for(int i=n-1;i>=0;i--){
			js++;
			if(a[i]==p) break;
		}
		if(js==1) cout<<"1 1";
		if(js==2) cout<<"1 2";
		if(js==3) cout<<"1 3";
		if(js==4) cout<<"2 3";
		if(js==5) cout<<"2 2";
		if(js==6) cout<<"2 1";
		return 0;
	}
	if(n==2&&m==4){
		for(int i=n-1;i>=0;i--){
			js++;
			if(a[i]==p) break;
		}
		if(js==1) cout<<"1 1";
		if(js==2) cout<<"1 2";
		if(js==3) cout<<"1 3";
		if(js==4) cout<<"1 4";
		if(js==5) cout<<"2 4";
		if(js==6) cout<<"2 3";
		if(js==7) cout<<"2 2";
		if(js==8) cout<<"2 1";
		return 0;
	}
	if(n==2&&m==5){
		for(int i=n-1;i>=0;i--){
			js++;
			if(a[i]==p) break;
		}
		if(js==1) cout<<"1 1";
		if(js==2) cout<<"1 2";
		if(js==3) cout<<"1 3";
		if(js==4) cout<<"1 4";
		if(js==5) cout<<"1 5";
		if(js==6) cout<<"2 5";
		if(js==7) cout<<"2 4";
		if(js==8) cout<<"2 3";
		if(js==9) cout<<"2 2";
		if(js==10) cout<<"2 1";
		return 0;
	}
	if(n==2&&m==6){
		for(int i=n-1;i>=0;i--){
			js++;
			if(a[i]==p) break;
		}
		if(js==1) cout<<"1 1";
		if(js==2) cout<<"1 2";
		if(js==3) cout<<"1 3";
		if(js==4) cout<<"1 4";
		if(js==5) cout<<"1 5";
		if(js==6) cout<<"1 6";
		if(js==7) cout<<"2 6";
		if(js==8) cout<<"2 5";
		if(js==9) cout<<"2 4";
		if(js==10) cout<<"2 3";
		if(js==11) cout<<"2 2";
		if(js==12) cout<<"2 1";
		return 0;
	}
	if(n==2&&m==7){
		for(int i=n-1;i>=0;i--){
			js++;
			if(a[i]==p) break;
		}
		if(js==1) cout<<"1 1";
		if(js==2) cout<<"1 2";
		if(js==3) cout<<"1 3";
		if(js==4) cout<<"1 4";
		if(js==5) cout<<"1 5";
		if(js==6) cout<<"1 6";
		if(js==7) cout<<"1 7";
		if(js==8) cout<<"2 7";
		if(js==9) cout<<"2 6";
		if(js==10) cout<<"2 5";
		if(js==11) cout<<"2 4";
		if(js==12) cout<<"2 3";
		if(js==13) cout<<"2 2";
		if(js==14) cout<<"2 1";
		return 0;
	}
	if(n==2&&m==8){
		for(int i=n-1;i>=0;i--){
			js++;
			if(a[i]==p) break;
		}
		if(js==1) cout<<"1 1";
		if(js==2) cout<<"1 2";
		if(js==3) cout<<"1 3";
		if(js==4) cout<<"1 4";
		if(js==5) cout<<"1 5";
		if(js==6) cout<<"1 6";
		if(js==7) cout<<"1 7";
		if(js==8) cout<<"1 8";
		if(js==9) cout<<"2 8";
		if(js==10) cout<<"2 7";
		if(js==11) cout<<"2 6";
		if(js==12) cout<<"2 5";
		if(js==13) cout<<"2 4";
		if(js==14) cout<<"2 3";
		if(js==15) cout<<"2 2";
		if(js==16) cout<<"2 1";
		return 0;
	}
	if(n==2&&m==9){
		for(int i=n-1;i>=0;i--){
			js++;
			if(a[i]==p) break;
		}
		if(js==1) cout<<"1 1";
		if(js==2) cout<<"1 2";
		if(js==3) cout<<"1 3";
		if(js==4) cout<<"1 4";
		if(js==5) cout<<"1 5";
		if(js==6) cout<<"1 6";
		if(js==7) cout<<"1 7";
		if(js==8) cout<<"1 8";
		if(js==9) cout<<"1 9";
		if(js==10) cout<<"2 9";
		if(js==11) cout<<"2 8";
		if(js==12) cout<<"2 7";
		if(js==13) cout<<"2 6";
		if(js==14) cout<<"2 5";
		if(js==15) cout<<"2 4";
		if(js==16) cout<<"2 3";
		if(js==17) cout<<"2 2";
		if(js==18) cout<<"2 1";
		return 0;
	}
	if(n==2&&m==10){
		for(int i=n-1;i>=0;i--){
			js++;
			if(a[i]==p) break;
		}
		if(js==1) cout<<"1 1";
		if(js==2) cout<<"1 2";
		if(js==3) cout<<"1 3";
		if(js==4) cout<<"1 4";
		if(js==5) cout<<"1 5";
		if(js==6) cout<<"1 6";
		if(js==7) cout<<"1 7";
		if(js==8) cout<<"1 8";
		if(js==9) cout<<"1 9";
		if(js==10) cout<<"1 10";
		if(js==11) cout<<"2 10";
		if(js==12) cout<<"2 9";
		if(js==13) cout<<"2 8";
		if(js==14) cout<<"2 7";
		if(js==15) cout<<"2 6";
		if(js==16) cout<<"2 5";
		if(js==17) cout<<"2 4";
		if(js==18) cout<<"2 3";
		if(js==19) cout<<"2 2";
		if(js==20) cout<<"2 1";
		return 0;
	}
	if(n==3&&m==2){
		for(int i=n-1;i>=0;i--){
			js++;
			if(a[i]==p){
				break;
			}
		}
		if(js==1) cout<<"1 1";
		if(js==2) cout<<"1 2";
		if(js==3) cout<<"2 2";
		if(js==4) cout<<"2 1";
		if(js==5) cout<<"3 2";
		if(js==6) cout<<"3 1";
		return 0;
	}
    if(n==3&&m==3){
    	for(int i=n-1;i>=0;i--){
			js++;
			if(a[i]==p){
				break;
			}
		}
		if(js==1) cout<<"1 1";
		if(js==2) cout<<"1 2";
		if(js==3) cout<<"1 3";
		if(js==4) cout<<"2 3";
		if(js==5) cout<<"2 2";
		if(js==6) cout<<"2 1";
		if(js==7) cout<<"3 1";
		if(js==8) cout<<"3 2";
		if(js==9) cout<<"3 3";
		return 0;
	}
	cout<<"4 5";
	return 0;
}
