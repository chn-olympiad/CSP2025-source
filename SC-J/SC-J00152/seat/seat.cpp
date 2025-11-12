#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int root;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)root=a[i];
	}
	sort(a+1,a+1+n*m);
	int x=1,y=1;
	if(a[n*m]==root){
		cout<<"1 1";
		return 0;
	}
	for(int i=n*m-1;i>=1;i--){
		if(x%2){
			y++;
			if(y==n+1){
				x++;
				y=n;
			}
		}else{
			y--;
			if(y==0){
				x++;
				y=1;
			}
		}
		if(a[i]==root){
			cout<<x<<" "<<y;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}