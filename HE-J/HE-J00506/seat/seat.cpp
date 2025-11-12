#include<bits/stdc++.h>
using namespace std;
int m,n,a[101],x=1,y=1,bj=1,mi,ma,js=1;
int cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		ma=a[1];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==ma){
			mi=i;
			break;
		}
	}
	while(1){
		if(js==mi){
			cout<<x<<" "<<y;
			break;
		}
		
		if(y==m && bj==1 &&m!=1){
			x++;
			bj=-1;
			js++;
		}else if(y==1 && bj==-1){
			bj=1;
			x++;
			js++;
		}else{
			y+=bj;
			js++;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 1;
}

