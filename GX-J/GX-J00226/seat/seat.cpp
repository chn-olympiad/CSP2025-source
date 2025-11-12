#include<bits/stdc++.h>
using namespace std;
int a[150];
int arr[150][150];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x=n*m;
	int R=0;
	for(int i=1;i<=x;i++){
		cin>>a[i];
		R=a[1];
	}
	if(n==1 && m==1){
		cout<<"1"<<" "<<"1";
		return 0;
	}	
	sort(a+1,a+x+1,cmp);
	if(n==2 && m==2){
		if(a[1]==R){
			cout<<"1"<<" "<<"1";
			return 0;
		}
		if(a[2]==R){
			cout<<"1"<<" "<<"2";
			return 0;
		}
		if(a[3]==R){
			cout<<"2"<<" "<<"2";
			return 0;
		}
		if(a[4]==R){
			cout<<"2"<<" "<<"1";
			return 0;
		}		
	}
	if(m==2){
		int k=x/2;
		for(int i=1;i<=k;i++){
			if(a[i]==R){
				cout<<"1"<<" "<<i;
				return 0;
			}
		}
		for(int i=k;i<=x;i++){
			if(a[i]==R){			
				cout<<"2"<<" "<<n-i/2;
				return 0;
			}
		}	
	}
	while(x--){
		int y=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(i==1 && j==1){
					arr[i][j]=a[y];	
				}
				if(j%2!=0){
					arr[i][j]=a[y];
					arr[i+1][j]=a[y+1];
				}
				if(j%2==0){
					arr[i][j]=a[y];
					arr[i-1][j]=a[y+1];
				}
				if(i==n || i==1){
					arr[i][j]=a[y];
					arr[i][j+1]=a[y+1];
				}
				arr[i][j]=a[y];
				y++;
				if(a[y]==R){
					if(n!=1 && m!=1){
							cout<<i<<" "<<j;
							return 0;
					}else{
						if(n==1 && m!=1){
							cout<<i<<" "<<j+1;
							return 0;
						}else{
							cout<<i+1<<" "<<j;
							return 0;
						}
					}	
 				}
			}
		}
	}
	return 0;
}
