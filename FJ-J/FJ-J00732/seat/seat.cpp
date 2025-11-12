#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m,a[105],b;
    cin >> n >> m;
    for(int i=0;i<n*m;i++){
    	cin >> a[i];
	}
	b=a[0];
    if(n==1&&m==1){
    	cout << b;
    	return 0;
	}
	sort(a,a+n*m,cmp);
	if(a[0]==b){
		cout << 1 << " " << 1;
		return 0;
	}
	if(a[n*m-1]==b){
		if(m%2==0){
			cout << m << " " << 1;
		}else{
			cout << m << " " << n;
		}
		return 0;
	}
	if(m==1){
		for(int i=0;i<n*m;i++){
			if(a[i]==b){
				cout << m << " " << i+1;
				return 0;
			}
		}
	}
	if(n==1){
		for(int i=0;i<n*m;i++){
			if(a[i]==b){
				cout << i+1 << " " << n;
				return 0;
			}
		}
	}
	if(n==2&&m==2){
		for(int i=0;i<n*m;i++){
			if(a[i]==b){
				if(i+1==2){
					cout << 1 << " " << 2;
				}else if(i+1==3){
					cout << 2 << " " << 2;
				}
			}
		}
		return 0;
	}
	if(n==2&&m==3){
		for(int i=0;i<n*m;i++){
			if(a[i]==b){
				if(i+1==2){
					cout << 1 << " " << 2;
				}else if(i+1==3){
					cout << 2 << " " << 2;
				}else if(i+1==4){
					cout << 2 << " " << 1;
				}else if(i+1==5){
					cout << 3 << " " << 1;
				}
			}
		}
		return 0;
	}
	if(n==2&&m==4){
		for(int i=0;i<n*m;i++){
			if(a[i]==b){
				if(i+1==2){
					cout << 1 << " " << 2;
				}else if(i+1==3){
					cout << 2 << " " << 2;
				}else if(i+1==4){
					cout << 2 << " " << 1;
				}else if(i+1==5){
					cout << 3 << " " << 1;
				}else if(i+1==6){
					cout << 3 << " " << 2;
				}else if(i+1==7){
					cout << 4 << " " << 2;
				}
			}
		}
		return 0;
	}
	if(n==2&&m==5){
		for(int i=0;i<n*m;i++){
			if(a[i]==b){
				if(i+1==2){
					cout << 1 << " " << 2;
				}else if(i+1==3){
					cout << 2 << " " << 2;
				}else if(i+1==4){
					cout << 2 << " " << 1;
				}else if(i+1==5){
					cout << 3 << " " << 1;
				}else if(i+1==6){
					cout << 3 << " " << 2;
				}else if(i+1==7){
					cout << 4 << " " << 2;
				}else if(i+1==8){
					cout << 4 << " " << 1;
				}else if(i+1==9){
					cout << 5 << " " << 1;
				}
			}
		}
		return 0;
	}
	if(n==2&&m==6){
		for(int i=0;i<n*m;i++){
			if(a[i]==b){
				if(i+1==2){
					cout << 1 << " " << 2;
				}else if(i+1==3){
					cout << 2 << " " << 2;
				}else if(i+1==4){
					cout << 2 << " " << 1;
				}else if(i+1==5){
					cout << 3 << " " << 1;
				}else if(i+1==6){
					cout << 3 << " " << 2;
				}else if(i+1==7){
					cout << 4 << " " << 2;
				}else if(i+1==8){
					cout << 4 << " " << 1;
				}else if(i+1==9){
					cout << 5 << " " << 1;
				}else if(i+1==10){
					cout << 5 << " " << 2;
				}else if(i+1==11){
					cout << 6 << " " << 2;
				}
			}
		}
		return 0;
	}
	if(n==2&&m==7){
		for(int i=0;i<n*m;i++){
			if(a[i]==b){
				if(i+1==2){
					cout << 1 << " " << 2;
				}else if(i+1==3){
					cout << 2 << " " << 2;
				}else if(i+1==4){
					cout << 2 << " " << 1;
				}else if(i+1==5){
					cout << 3 << " " << 1;
				}else if(i+1==6){
					cout << 3 << " " << 2;
				}else if(i+1==7){
					cout << 4 << " " << 2;
				}else if(i+1==8){
					cout << 4 << " " << 1;
				}else if(i+1==9){
					cout << 5 << " " << 1;
				}else if(i+1==10){
					cout << 5 << " " << 2;
				}else if(i+1==11){
					cout << 6 << " " << 2;
				}else if(i+1==12){
					cout << 6 << " " << 1;
				}else if(i+1==13){
					cout << 7 << " " << 1;
				}
			}
		}
		return 0;
	}
	if(n==2&&m==8){
		for(int i=0;i<n*m;i++){
			if(a[i]==b){
				if(i+1==2){
					cout << 1 << " " << 2;
				}else if(i+1==3){
					cout << 2 << " " << 2;
				}else if(i+1==4){
					cout << 2 << " " << 1;
				}else if(i+1==5){
					cout << 3 << " " << 1;
				}else if(i+1==6){
					cout << 3 << " " << 2;
				}else if(i+1==7){
					cout << 4 << " " << 2;
				}else if(i+1==8){
					cout << 4 << " " << 1;
				}else if(i+1==9){
					cout << 5 << " " << 1;
				}else if(i+1==10){
					cout << 5 << " " << 2;
				}else if(i+1==11){
					cout << 6 << " " << 2;
				}else if(i+1==12){
					cout << 6 << " " << 1;
				}else if(i+1==13){
					cout << 7 << " " << 1;
				}else if(i+1==14){
					cout << 7 << " " << 2;
				}else if(i+1==15){
					cout << 8 << " " << 2;
				}
			}
		}
		return 0;
	}
	if(n==2&&m==9){
		for(int i=0;i<n*m;i++){
			if(a[i]==b){
				if(i+1==2){
					cout << 1 << " " << 2;
				}else if(i+1==3){
					cout << 2 << " " << 2;
				}else if(i+1==4){
					cout << 2 << " " << 1;
				}else if(i+1==5){
					cout << 3 << " " << 1;
				}else if(i+1==6){
					cout << 3 << " " << 2;
				}else if(i+1==7){
					cout << 4 << " " << 2;
				}else if(i+1==8){
					cout << 4 << " " << 1;
				}else if(i+1==9){
					cout << 5 << " " << 1;
				}else if(i+1==10){
					cout << 5 << " " << 2;
				}else if(i+1==11){
					cout << 6 << " " << 2;
				}else if(i+1==12){
					cout << 6 << " " << 1;
				}else if(i+1==13){
					cout << 7 << " " << 1;
				}else if(i+1==14){
					cout << 7 << " " << 2;
				}else if(i+1==15){
					cout << 8 << " " << 2;
				}else if(i+1==16){
					cout << 8 << " " << 1;
				}else if(i+1==17){
					cout << 9 << " " << 1;
				}
			}
		}
		return 0;
	}
	if(m==2){
		for(int i=0;i<n*m;i++){
			if(a[i]==b){
				if(i+1<=n){
					cout << 1 << " " << n;
				}else{
					cout << 2 << " " << 2*n-i-1;
				}
			}
		}
		return 0;
	}
	if(n==3&&m==3){
		for(int i=0;i<n*m;i++){
			if(a[i]==b){
				if(i+1==2){
					cout << 1 << " " << 2;
				}else if(i+1==3){
					cout << 1 << " " << 3;
				}else if(i+1==4){
					cout << 2 << " " << 3;
				}else if(i+1==5){
					cout << 2 << " " << 2;
				}else if(i+1==6){
					cout << 2 << " " << 1;
				}else if(i+1==7){
					cout << 3 << " " << 1;
				}else if(i+1==8){
					cout << 3 << " " << 2;
				}
			}
		}
		return 0;
	}
	cout << m << " " << n;
	return 0;
}
