#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[110];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1;
	int i=1;
	int y=1;
	bool v=0;
	bool qishi=1;
	while(a[i]!=k){
		if(qishi==1&&n!=1){
			x++;
			i++;
			qishi=0;
			continue;
		}
		if(v==0){
			if(x!=n){
				x++;
				i++;
				continue;
			}
			if(x==n){
				y++;
				i++;
				v=1;
				continue;
			}
		}
		else{
			if(x!=1){
				x--;
				i++;
				continue;
			}
			else{
				y++;
				i++;
				v=0;
				continue;
			}
		}
	}
	cout<<y<<" "<<x;
	return 0;
}