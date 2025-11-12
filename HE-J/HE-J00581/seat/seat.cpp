#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[50][50],b[500];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,now_m=1,now_n=1,r;
	cin>>n>>m;
	for(int i=1;i<=(n*m);i++){
		cin>>b[i];
	}
	r=b[1];
	sort(b+1,b+n*m+1);
	bool f=true;
	for(int i=(n*m);i>=1;i--){
		if(b[i]==r){
			cout<<now_m<<" "<<now_n;
			return 0;
		}
		if(f){
			if(now_n%n==0){
				a[now_n][now_m]=b[i];
				now_m++;
				f=false;
			}
			else{
				a[now_n][now_m]=b[i];
				now_n++;
			}
		}
		else{
			if(now_n==1){
				a[now_n][now_m]=b[i];
				now_m++;
				f=true;
			}
			else{
				a[now_n][now_m]=b[i];
				now_n--;
			}
		}
	}
	return 0;
}
