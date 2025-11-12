#include<iostream>
using namespace std;
int n=0,m=0,c=0,a=0,ad=0;
int num[105];
int p[15][15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>num[i];
		if(i==1){
			a=num[i];
		}
	}
	for(int i=1;i<=m*n;i++){
		for(int j=i+1;j<=m*n;j++){
			if(num[j]>num[i]){
				c=num[i];
				num[i]=num[j];
				num[j]=c;
				c=0;
			}
		}
	}
	for(int i=1;i<=m*n;i++){
		if(num[i]==a){
			ad=i;
		}
	}
	if(ad<=n){
		cout<<1<<" "<<ad;
		return 0;
	}
	cout<<ad/n+1<<" ";
	if((ad/n+1)%2==1){
		cout<<ad-(ad/n)*n; 
	}else{
		cout<<n-(ad-(ad/n)*n)+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
