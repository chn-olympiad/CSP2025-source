#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[103],d=0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}d=a[0];
	sort(a,a+m*n,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==d){
			if(i+1-m<=0) cout<<1<<" "<<i+1;
			else if(i+1-2*m<=0) cout<<2<<" "<<m-i%n;
			else if(i+1-3*m<=0) cout<<3<<" "<<(i+1)%n;
			else if(i+1-4*m<=0) cout<<4<<" "<<m-i%n;
			else if(i+1-5*m<=0) cout<<5<<" "<<(i+1)%n;
			else if(i+1-6*m<=0) cout<<6<<" "<<m-i%n;
			else if(i+1-7*m<=0) cout<<7<<" "<<(i+1)%n;
			else if(i+1-8*m<=0) cout<<8<<" "<<m-i%n;
			else if(i+1-9*m<=0) cout<<9<<" "<<(i+1)%n;
			else if(i+1-10*m<=0) cout<<10<<" "<<m-i%n;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
