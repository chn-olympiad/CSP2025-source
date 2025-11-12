#include<bits/stdc++.h>
using namespace std;
int n,m,q,p=1,x[105];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<n*m;i++){
		cin >> x[i];
	}
	q=x[1];
	sort(x+1,x+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(x[p]==q){
					cout << i << " " << j;
					return 0;
				}
				p++;
			}
		}else{
			for(int j=n;j>=1;j--){
				if(x[p]==q){
					cout << i << " " << j;
					return 0;
				}
				p++;
			}
		}
	}
	return 0;
}

