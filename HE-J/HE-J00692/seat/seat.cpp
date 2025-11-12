#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000],mi,p=1,b[15][15];
bool cmp(int b,int c){
	if(b>c)return b>c;
	else return b>c;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	mi=a[1]; 
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++) cout<<a[i]<<"  ";
	cout<<endl;
	for(int i=1;i<=m;i++){
		if(i%2==1){
		 	for(int j=1;j<=n;j++) {
				b[j][i]=a[p];
				p++;}
		}
		else{
			for(int j=n;j>=1;j--){
				b[j][i]=a[p];
				p++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[j][i]==mi){
			cout<<i<<" "<<j;break;}
		}
	}
	return 0;
}
