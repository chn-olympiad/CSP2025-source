#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,tot,pz;
int a[110];
bool cmp(int A,int B){
	return A>B;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	tot=n*m;
	for(int i=1;i<=tot;i++){
		cin>>a[i];
	}
	pz=a[1];
	sort(a+1,a+1+tot,cmp);
	int ptr=1;
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				if(a[ptr]==pz){
					cout<<i<<" "<<j;
					return 0;
				}
				ptr++;
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[ptr]==pz){
					cout<<i<<" "<<j;
					return 0;
				}
				ptr++;
			}
		}
	}
	return 0;
}