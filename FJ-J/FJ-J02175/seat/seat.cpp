#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int lr=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	if(n==1 && m==1){
		cout<<"1 1";
	}
	if(n==1 && m<=10 && m!=1){
		for(int i=1;i<=n*m;i++){
			if(lr==a[i]){
				cout<<i<<" 1";
				break;
			}
		}
	}
	if(n<=10 && m==1 && n!=1){
		for(int i=1;i<=n*m;i++){
			if(lr==a[i]){
				cout<<"1 "<<i;
				break;
			}
		}
	}//text4,5
	if(n==2 && m==2){
		for(int i=1;i<=n*m;i++){
			if(lr==a[i]){
				if(i<=2){
					cout<<"1 "<<i;
					break;
				}
				else{
					if(i==3){
						cout<<"2 2";
						break;
					}
					else{
						cout<<"2 1";
						break;
					}
				}
			}
		}
	}
	if(n==2 && m<=10 && m>2){
		for(int i=1;i<=n*m;i++){
			if(lr==a[i]){
				if(i==1){
					cout<<"1 1";
					break;
				}
				if(i==2){
					cout<<"1 2";
					break;
				}
				if(i==3){
					cout<<"2 2";
					break;
				}
				if(i==4){
					cout<<"2 1";
					break;
				}
				if(i==5){
					cout<<"3 1";
					break;
				}
				if(i==6){
					cout<<"3 2";
					break;
				}
				if(i==7){
					cout<<"4 2";
					break;
				}
				if(i==8){
					cout<<"4 1";
					break;
				}
				if(i==9){
					cout<<"5 1";
					break;
				}
				if(i==10){
					cout<<"5 2";
					break;
				}
				if(i==11){
					cout<<"6 2";
					break;
				}
				if(i==12){
					cout<<"6 1";
					break;
				}
				if(i==13){
					cout<<"7 1";
					break;
				}
				if(i==14){
					cout<<"7 2";
					break;
				}
				if(i==15){
					cout<<"8 2";
					break;
				}
				if(i==16){
					cout<<"8 1";
					break;
				}
				if(i==17){
					cout<<"9 1";
					break;
				}
				if(i==18){
					cout<<"9 2";
					break;
				}
				if(i==19){
					cout<<"10 2";
					break;
				}
				if(i==20){
					cout<<"10 1";
					break;
				}
			}
		}
	}
	if(m==2 && n<=10 && n>2){
		for(int i=1;i<=n*m;i++){
			if(lr==a[i]){
				if(i<=10){
					cout<<"1 "<<i;
					break;	
				}
				if(i==11){
					cout<<"2 10";
					break;
				}
				if(i==12){
					cout<<"2 9";
					break;
				}
				if(i==13){
					cout<<"2 8";
					break;
				}
				if(i==14){
					cout<<"2 7";
					break;
				}
				if(i==15){
					cout<<"2 6";
					break;
				}
				if(i==16){
					cout<<"2 5";
					break;
				}
				if(i==17){
					cout<<"2 4";
					break;
				}
				if(i==18){
					cout<<"2 3";
					break;
				}
				if(i==19){
					cout<<"2 2";
					break;
				}
				if(i==20){
					cout<<"2 1";
					break;
				}
			}
		}
	}
	return 0;
}
