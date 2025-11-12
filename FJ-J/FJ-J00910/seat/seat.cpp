#include<bits/stdc++.h>
using namespace std;
int n,m,r,l=1,ll=1,a[105],b[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >>a[l];
			l++;
		}
	}
	r=a[1];
	sort(a+1,a+l,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++,ll++){
				if(a[ll]==r){
					cout <<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--,ll++){
				if(a[ll]==r){
					cout <<i<<" "<<j;
					return 0;
				}
				
			}
		}
	}
	return 0;
}
