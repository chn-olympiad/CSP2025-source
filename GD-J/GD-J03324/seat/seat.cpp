#include<bits/stdc++.h>
using namespace std;
int a[109];
int xiaor;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n*m;++i){
		cin>>a[i];
		if(i == 1) xiaor = a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int x = 1,y = 1,k = 0;
	while(1){
		k++;
		if(a[k] == xiaor){
			cout<<y<<" "<<x;
			return 0;
		}
		if(y&1){
			if(x == n) y++;
			else x++;
		}else{
			if(x == 1) y++;
			else x--;
		}
	}
	fclose(stdin);
	fclose(stdout);
}

