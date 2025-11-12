#include<bits/stdc++.h>
using namespace std;
const int N=1e7+7;
//T2 :100pts
//注意 freopen用了吗 ll要开吗 N大小够吗
int n,m,a[N],f,wz;
bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	} 
	f=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==f){
			wz=i;
		}
	}
	for(int i=1;i<=m;i++){
		if(wz<=n){
			if(i%2==1){
				cout<<i<<" "<<wz;
				return 0;
			}
			else{
				cout<<i<<" "<<n-wz+1;
				return 0;
			}
		}
		wz-=n;
	}
	return 0;
}
/*  o_O  */
