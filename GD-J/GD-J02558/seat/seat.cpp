#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,a[N],j=1,t,sum;
bool cmd(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	sum=a[0];
	sort(a,a+n*m,cmd);
	while(j<=m){
		if(j%2==1){
			for(int k=1;k<=n;k++){
				if(a[t]==sum){
					cout<<j<<" "<<k;
					return 0;
				}
				t++;
			}
		}else{
			for(int k=n;k>=1;k--){
				if(a[t]==sum){
					cout<<j<<" "<<k;
					return 0;
				}
				t++;
			}
		}
		j++;
	}
	return 0;
} 
