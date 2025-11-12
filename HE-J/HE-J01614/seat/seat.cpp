#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[15][15],cj[115],q = 1,R;
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n*m;i++){
		cin>>cj[i];
	}
	R = cj[1];
	sort(cj+1,cj+n*m+1,cmp);
	for(int i = 1;i <= m;i++){
		if(i % 2 == 1){
			for(int j = 1;j <= n;j++){
				a[j][i] = cj[q];
				q++;
			}
		}else if(i % 2 == 0){
			for(int j = n;j >= 1;j--){
				a[j][i] = cj[q];
				q++;
			}
		}
	}
//	for(int i = 1;i <= m;i++){
//		for(int j = 1;j <= n;j++){
//			cout<<a[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= n;j++){
			if(a[i][j] == R){
				cout<<j<<" "<<i;
			}
		} 
	}
	return 0;
}
