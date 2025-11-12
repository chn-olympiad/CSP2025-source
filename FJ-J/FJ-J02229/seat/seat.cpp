#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m,num,rr;
int a[105];
int b[105][105];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("sear.out","w",stdout);
	cin >>n>>m;
	num=n*m;
	for(int i=1;i<=num;i++){
		cin >>a[i];
		if(i==1)rr=a[i];
	}
	sort(a+1,a+1+num);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				if(a[num]==rr){
					cout <<i<<" ";
					cout <<j;
					return 0;
				}
				num--;
			}
		}else 
			for(int j=m;j>=1;j--){
				if(a[num]==rr){
					cout <<i<<" ";
					cout <<j;
					return 0;
				}
				num--;
			}
	}
	
	return 0;
}
