#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,b[100][100],num=0, a[10005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+1+sum,cmp);
	int cnt=1,i=1,j=1;
	while(1){
		if(cnt>=sum){
			break;
		}
		while(b[i][j]==0&&i<=n){
			b[i][j]=a[cnt];
			cnt++;
			i++;
		}
		i--;
		if(cnt>=sum){
			break;
		}
		j++;
		while(b[i][j]==0&&i>=1){
			b[i][j]=a[cnt];
			cnt++;
			i--;
		}
		i++;
		if(cnt>=sum){
			break;
		}
		j++;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(b[i][j]==num){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
