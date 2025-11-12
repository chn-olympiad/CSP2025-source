#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[520],x,y,cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			y=i;
			break;
		}
	}
	int z=0;
	for(int j=1;j<=m;j++){
		if(j%2!=0){
			for(int i=1;i<=n;i++){
				z++;
				if(z==y){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
		else{
			for(int i=n;i>=1;i--){
				z++;
				if(z==y){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
