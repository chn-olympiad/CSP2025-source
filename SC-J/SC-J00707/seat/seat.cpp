#include<bits/stdc++.h>
using namespace std;

const int N=10;
int a[N*N+10],s[N+10][N+10];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int a1=a[1];
	sort(a+1,a+n*m+1,cmp);
	int px=1,py=1;
	for(int i=1;i<=n*m;i++){
		if(a1==a[i])break;
		if(px%2){
			if(py<n)py++;
			else px++;
		}else{
			if(py>1)py--;
			else px++;
		}
	}
	cout<<px<<' '<<py;
	
	fclose(stdin);fclose(stdout);
	return 0;

}
