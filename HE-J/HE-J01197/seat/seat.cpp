#include<bits/stdc++.h>
using namespace std;
int a[50][50],b[105],c[100];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;//列数，行数；
	 
	for(int i=1;i<=n*m;i++)
	cin>>b[i];//分 
	c[1]=b[1];
	sort(b+1,b+n*m+1,cmp);//由高到低排序 
int cm=1;
	for(int i=1;i<=n*m;i++){
//		cout<<b[i];
		if(b[i]==c[1]){
			 cm=i;
			 break;
		}
	}
//	cout<<cm;
//	return 0;
	int d=0; 
	for(int i=1;i<=n;i++){//列数 
	  if(i%2==0){
	  	for(int j=m;j>=1;j--){//行数 
			d++;
			if(d==cm){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	  }
	  else{
	  	for(int j=1;j<=m;j++){
	  		d++;
	  		if(d==cm){
	  			cout<<i<<" "<<j;
	  			return 0;
			  }
		  }
	  }
	}
	fclose(stdin);
	fclose(stdout);
}
