#include<bits/stdc++.h>
using namespace std;
const int N=1e1+5;
int a[N][N],b[N*N],n,m,num,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	num=b[1];
	int s=m%2;
	sort(b+1,b+n*m+1);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				cnt++; 
				a[j][i]=b[n*m-cnt+1];
				if(a[j][i]==num){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				cnt++;
				a[j][i]=b[n*m-cnt+1];
				if(a[j][i]==num){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
}