#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
long long n,m;
long long id=1,r;
long long ans_r,ans_c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	for(int i=2;i<=n*m;i++){
		long long g;
		cin>>g;
		if(g>r){
			id++;
		}
	}
	ans_c=id/n;
	if(id%n!=0)	ans_c++;
	ans_r=id%n;
	if(ans_r==0)	ans_r=n;
	if(ans_c%2==0){
		ans_r=n-ans_r+1;
	}
	cout<<ans_c<<' '<<ans_r<<endl;
	return 0;
}
//3 3 
//94 95 96 97 98 99 100 93 92
//3 1
