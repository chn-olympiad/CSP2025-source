#include<bits/stdc++.h>
using namespace std;
long long cj[1008];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n,m;
	cin>>n>>m;
	long long r;
	cin>>r;
	cj[0]=r;
	int seat=1;
	for(long long i=1;i<n*m;i++){
		cin>>cj[i];
		if(cj[i]>r){
			seat++;
		}
	}

	int hang;
	if((seat/n+1)%2!=0){
		hang=seat%n;
	}else{
		hang=n-seat%(n-1);
	}
	cout<<seat/n+1<<" "<<hang;
	cout<<flush;
	return 0;
}
