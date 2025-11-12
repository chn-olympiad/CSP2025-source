#include <bits/stdc++.h>
using namespace std;
long long a[100],book[15][15];
bool cmp(int r,int c){
	return r>c;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	long long R=a[1];
	sort(a+1,a+1+n*m,cmp);
	long long cnt=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				cnt++;
				if(a[cnt]==R){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				cnt++;
				if(a[cnt]==R){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}
	}
	
	return 0;
}
