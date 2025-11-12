#include<bits/stdc++.h>
using namespace std;
const int N=10;
int a[N*N+10],s[N+10][N+10];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	long long a1=a[1];
	sort(a+1,a+n*m+1,cmp);
	long long lx=1,ly=1;
	for(int i=1;i<=m*n;i++){
		if(a1==a[i]){
			break;
		}
		if(lx%2){
			if(ly<n){
				ly++;
			}else{
				lx++;
			}
		}else{
			if(ly>1){
				ly--;
			}else{
				lx++;
			}
		}
	}
	cout<<lx<<" "<<ly;
	
	fclose(stdin);fclose(stdout);
	return 0;
}