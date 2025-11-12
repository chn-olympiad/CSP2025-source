#include <bits/stdc++.h>
using namespace std;
int a[205],b[100][100];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int idx=-1;
	int i=1,j=1,cnt=0;
	int flg=0;
	while (i<=n && j<=m){
		b[i][j]=a[++cnt];
		if (flg==0){
			if (j<n) j++;
			else{
				i++;
				flg=1-flg;
			}
		}else if (flg==1){
			if (j>1) j--;
			else{
				i++;
				flg=1-flg;
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (b[i][j]==r){
				cout << i << " " << j;
				return 0;
			}
		}
	}
	return 0;
}
