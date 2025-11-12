#include<bits/stdc++.h>
using namespace std;//开long long!
long long a[101][101];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);//注释删掉!
	freopen("seat.out","w",stdout);//注释删掉!
	long long n,m,b[100010],i,j,flag,k=0;
	cin>>n>>m;
	cin>>b[0];
	flag=b[0];
	for(i=1;i<n*m;i++){
		cin>>b[i];
	}
	sort(b,b+n*m,cmp);
	for(i=0;i<n;i++){
		if(i%2==0){
			for(j=0;j<m;j++){
				a[i][j]=b[k];
				if(a[i][j]==flag){
					cout<<i+1<<' '<<j+1;
					return 0;
				}
				k++;
			}
		}else{
			for(j=m-1;j>=0;j--){
				a[i][j]=b[k];
				if(a[i][j]==flag){
					cout<<i+1<<' '<<j+1;
					return 0;
				}
				k++;
			}
		}
	}
	return 0;
}
