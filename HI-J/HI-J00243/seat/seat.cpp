#include<bits/stdc++.h>
using namespace std;
int n,m,t;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n+3][m+3],x=n*m;
	int b[x+3],k;
	for(int i=1;i<=x;i++){
			cin>>b[i];
			if(i==1)t=b[i];
	}
	sort(b+1,b+x+1,cmp);
	for(int i=1;i<=x;i++){
			if(t==b[i])k=i;
	}
	int s=1;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>0;j--){
				a[j][i]=s;
				s++;
				if(a[j][i]==k){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=1;j<=n;j++){
				a[j][i]=s;
				s++;
				if(a[j][i]==k){
					cout<<i<<" "<<j;
					return 0;
				}
			}
			
		}
	}
	return 0;
}

