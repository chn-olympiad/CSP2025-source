#include<bits/stdc++.h>
using namespace std;
int n,m,ed;
int j=1,k=1,inx=1;
int a[105];
bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		if (i==1){
			cin>>ed;
			a[i]=ed;
			continue;
		}
		cin>>a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	while (1){
		if (a[inx]==ed){
			cout<<j<<" "<<k;
			break;
		}
		if ((k+1)%(n+2)<=n && j%2==1) k++;
		else if (j%2==0 && k-1>=1) k--;
		else j++;
		inx++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
