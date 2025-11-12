#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1234][1234];
int b[12345678];
int id;
int idd;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	id=b[1];
	sort(b+1,b+m*n+1,cmp);
	if(n==1){
		if(m==1){
			cout<<1<<' '<<1;
			return 0;
		}
		else{
			for(int i=1;i<=m;i++){
				if(b[i]==id){
					cout<<1<<' '<<i;
					return 0;
				}
			}		
		}
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(b[i]==id){
				cout<<i<<' '<<1;
				return 0;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(b[i]==id){
			idd=i;
			break;	
		}
	}
	if(n<=2&&m<=2){
		if(idd==1)cout<<1<<' '<<1;
		else if(idd==2)cout<<1<<' '<<2;
		else if(idd==3)cout<<2<<' '<<2;
		else if(idd==4)cout<<2<<' '<<1;
		return 0;
	}
	if(m<=2){
		for(int i=1;i<=n;i++){
			if(2*i==idd){
				if(i%2==0)cout<<i<<' '<<1;
				else cout<<i<<' '<<2;
			}
			else{
				if(2*i-1==idd){
					if(i%2==1)cout<<i<<' '<<1;
					else cout<<i<<' '<<2;
				}
			}
		}
		
	}
	for(int i=n*m;i>=1;i--){
		if(b[i]==id){
			idd=n*m-i+2;
			break;
		}
	}
	int top=n*m+1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			top--;
			if(i%2==1){
				a[i][j]=b[top];
				if(b[top]==id){
					cout<<j<<' '<<i;
					return 0;
				}
			}
			else{
				a[i][m-j+1]=b[top];
				if(b[top]==id){
					cout<<m-j+1<<' '<<i;
					return 0;
				}
			}
		}
	}
	
	return 0;
}

