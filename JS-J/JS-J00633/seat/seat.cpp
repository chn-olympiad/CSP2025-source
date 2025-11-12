#include<bits/stdc++.h>
//tot_get:100
using namespace std;
int h[101];
int k[101];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int num;
	for(int i=1;i<=n*m;i++){
		cin>>num;
		h[num]=i;
	}
	int cnt=0;
	for(int i=100;i>=1;i--){
		if(h[i]){
			cnt++;
			k[h[i]]=cnt;
		}
	}
	int row=0;
	int q=k[1]%n;
	if(q!=0) row=k[1]/n+1;
	else row=k[1]/n;
	int col=0;
	if(row%2==0){
		if(q!=0){
			col=n+1-q;
		}else{
			col=1;
		}
	}
	else{
		if(q!=0){
			col=q;
		}else{
			col=n;
		}
	}
	cout<<row<<" "<<col;
	return 0;
}
