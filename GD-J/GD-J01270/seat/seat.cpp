#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[1001];
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int r=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(r==a[i]){
			r=i+1;
			break;
		}
	}
	int rp;
	int rl;
	rl=r/n;
	if(r%n!=0){
		rl++;
	}
	if(rl%2==1){
		rp=r%n;
		if(rp==0){
			rp=n;
		}
	}else{
		rp=n-(r%n)+1;
		if(rp>m){
			rp=1;
		}
	}
	cout<<rl<<' '<<rp;
}
