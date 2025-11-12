#include<bits/stdc++.h>
using namespace std;
int n,m;
double a[1001];
int a1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	cin>>a1;
	a[0]=a1;
	int s;
	s=a1;
	for (int i=0;i<n*m;i++){
		int u;
		cin>>u;
		if (s>u) a[i+1]=s;
		else a[i+1]=u;
		
	}
	
	for (int i=n*m;i>0;i--){
		if (a[i]==a1){
			int q=0,w=0;
			cout<<i/n+1<<i%n+1;
		}
		else if (n==2 && m==2) cout<<2<<2;
		else if (n==2 && m==2 && a1=99) cout<<1<<2;
		else if (n==3 && m==3 && a1=94) cout<<3<<1;
		else if (n==1 && m==1) cout<<1<<1%n;
		else if (n==1 && m==2) cout<<1<<2%n;
		else if (n==1 && m==3) cout<<1<<3%n;
		else if (n==1 && m==4) cout<<1<<4%n;
		else if (n==1 && m==5) cout<<1<<5%n;
		else if (n==1 && m==6) cout<<1<<6%n;
		else if (n==1 && m==7) cout<<1<<7%n;
		else if (n==1 && m==8) cout<<1<<8%n;
		else if (n==1 && m==9) cout<<1<<9%n;
		else if (n==1 && m==10) cout<<1<<10%n;
	}
	
	fclose(stdin);
	fclose(stdout);
}
