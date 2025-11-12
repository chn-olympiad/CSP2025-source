#include<bits/stdc++.h>
using namespace std;
int n,m,sum,cre,dis=1,c,r,fr,cuo[11][11];
void exp(){
	int fl=1;
	for(int i=1;i<=n;i++){
		if(i&1){
			for(int j=1;j<=m;j++){
				cuo[j][i]=fl;
				if(fl==dis)c=i,r=j;
				fl++;
			}
		}else{
			for(int j=m;j>=1;j--){
				cuo[j][i]=fl;
				if(fl==dis)c=i,r=j;
				fl++;
			}
		}
	}
	return ;
}
void fir(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<cuo[i][j]<<" ";
		}
		cout<<endl;
	}
	return ;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum=n*m;
	cin>>cre;
	for(int i=2;i<=sum;i++){
		int x;
		cin>>x;
		if(x>cre)dis++;
	}
	exp();
	cout<<c<<" "<<r;
	return 0;
}
