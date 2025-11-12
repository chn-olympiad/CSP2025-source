#include <bits/stdc++.h>
using namespace std;
int b[105];
int cmp(const int&a,const int&b){
	return a<b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,sum=1,cnt=0;
	cin>>n>>m;
	for(int i=1;i<m*n;i++){
		cin>>b[i];
		if(i==1){
			a=i;
		}
		if(b[i]>b[a]){
			cnt++;
		}
	}
	a=cnt;
	sort(begin(b),end(b),cmp);
	for(int j=1;j<=n;j++){
		for(int i=1;i<=m;i++){
			if(j==1){
				if(j+i-1==a){
					cout<<j<<" "<<i+1;
					return 0;
				}
			}else if((j-1)*m+i==a){
				if(j%2==1){
					cout<<j<<" "<<i;
				}else{
					cout<<j<<" "<<n-i+1;
				}
				return 0;
			}
		}
	}
}



 





















