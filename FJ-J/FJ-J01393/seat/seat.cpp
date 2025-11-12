#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int b[105];
int cmp(int x,int y){
	return x>y;	
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int r;
	int tit=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			tit++;
			cin>>b[tit];
			if(tit==1) r=b[tit];
		}
	}
	sort(b+1,b+1+tit,cmp);
	for(int i=1;i<=tit;i++){
		//cout<<b[i]<<endl;
		int x=i/n;
		if(i%n!=0) x++;
		int y=i%n;
		if(x%2==0){
			y=(5-y)%n;
		}
		if(y==0){
			a[n][x]=b[i];
			if(b[i]==r){
				cout<<x<<" "<<n<<endl;
				return 0;
			}
		}
		else{
			a[y][x]=b[i];	
			if(b[i]==r){
				cout<<x<<" "<<y<<endl;
				return 0;
			}
		}	
	}
	return 0;
}
