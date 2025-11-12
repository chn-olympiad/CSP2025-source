#include<bits/stdc++.h>
using namespace std;
int n,m,check,l=1,r,ind;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+1+(n*m),cmp);
	while(true){
		for(int i=1;i<=n;i++){
			ind++;
			if(r==a[ind]){
				cout<<l<<" "<<i;
				check=1;
				break;
			}
		}
		if(check==1) break;
		l++;
		for(int i=n;i>=1;i--){
			ind++;
			if(r==a[ind]){
				cout<<l<<" "<<i;
				check=1;
				break;
			}
		}
		if(check==1) break;
		l++;
	}
	return 0;
} 
