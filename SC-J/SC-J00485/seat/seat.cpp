#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int n,m,FP,a[N],cnt,P[1005][1005];
bool cmp(int x_200,int y_200){
	return x_200>y_200;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>a[i];
	}
	FP = a[1];
	sort(a+1,a+n*m+1,cmp);
	cnt = 1;
	for(int i = 1;i<=m;i++){
		if(i%2 == 1){
			for(int j = 1;j<=n;j++){
				P[j][i] = a[cnt];
				if(a[cnt] == FP){
					cout<<i<<" "<<j;
					return 0;
				}
				cnt++;
			}
		}
		else{
			for(int j = n;j>=1;j--){
				P[j][i] = a[cnt];
				if(a[cnt] == FP){
					cout<<i<<" "<<j;
					return 0;
				}
				cnt++;
			}
		}
	}
	return 0;
}