#include<bits/stdc++.h>
using namespace std;
long long a1,n,m,r=1,ls,dan,dam;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a1;
	for(long long i=1;i<n*m;i++){
		cin>>ls;
		if(ls>a1){
			r+=1;
		}
	}
	dam=r/n+1;
	dan=r%n;
	if(dan==0){
		dam-=1;
		if(dam%2==0){
			cout<<dam<<" "<<1;
		}else{
			cout<<dam<<" "<<n;
		}
	}else{
		if(dam%2==0){
			cout<<dam<<" "<<n-dan+1;
		}else{
			cout<<dam<<" "<<dan;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

