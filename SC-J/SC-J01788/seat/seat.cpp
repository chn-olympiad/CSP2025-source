#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[110];
	int s;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		s=a[1];
	}
	sort(a+1,a+1+(n*m),cmp);
	int b[110][110];
	int o=1;
	int k=0;
	for(int i=1;i<=n;i++){
		if(o==1){
			for(int j=1;j<=m;j++){
				k++;
				b[i][j]=a[k];
			}
			o=0;
		} else{
			for(int j=m;j>0;j--){
				k++;
				b[i][j]=a[k];
			}
			o=1;
		}
	}

	for(int i=1;i<=n;i++){	
		for(int j=1;j<=m;j++){
			if(b[j][i]==s){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}