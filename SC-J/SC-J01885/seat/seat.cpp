#include <bits/stdc++.h> 
using namespace std;

const int q=1e6+5;
long long number[q],n,m,r,s,rm,rn;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>number[i];
	}
	r=number[0];
	sort(number,number+n*m);
	for(int i=0;i<n*m;i++){
		if(r==number[i]){
			s=n*m-i;
			break;
		}
	}
	if(s%n==0){
		rm=s/n;
	}else{
		rm=s/n+1;
	}
	if(rm%2==1){
		rn=s%n;
		if(rn==0){
			rn=n;
		}
	}else{
		rn=s%n;
		if(rn==0){
			rn=1;
		}else{
			rn=n-rn+1;
		}
	}
	cout<<rm<<" "<<rn;
	return 0;
}
