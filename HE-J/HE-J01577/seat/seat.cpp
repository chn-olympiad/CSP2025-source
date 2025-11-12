#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=1010;
int z[M][M],b[N];
int n,m,nm;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	nm=n*m;
	for(int i=0;i<n*m;i++){
		cin>>b[i];
	}
	int benren=b[0];
	int mc;
	sort(b,b+nm,cmp);
	for(int i=0;i<nm;i++){
		if(b[i]==benren){
			mc=i+1;
			break;
		}
	}
	if(mc/n%2==0 && mc%n!=0){
		cout<<mc/n+1<<" "<<mc%n;
	} 
	else if(mc/n%2==1 && mc%n==0){
		cout<<mc/n<<" "<<n;
	} 
	else if(mc/n%2==1 && mc%n!=0){
		cout<<mc/n+1<<" "<<n-mc%n+1;
	}
	else{
		cout<<mc/n<<" "<<1;
	}
	return 0;
} 
