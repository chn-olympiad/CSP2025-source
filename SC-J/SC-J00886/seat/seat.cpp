#include<bits/stdc++.h>
using namespace std;
const int MAXN=110;
int a[MAXN];
int b[MAXN][MAXN];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int x=a[0],cnta=n*m-1,cnt=0;
	bool l=1;
	sort(a,a+n*m);
	for(int i=0;i<m;i++){
		if(i%2==0){
			l=0;
		}else{
			l=1;
		}
		if(l){
			for(int j=0;j<n;j++){
				b[i][j]=a[cnta];
				cnta--; 
			}
		}else{
			for(int j=n-1;j>=0;j--){
				b[i][j]=a[cnta];
				cnta--; 
			}
		}
	}

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(b[i][j]==x){
				cout<<i+1<<" "<<n-j;
			}
		}
	}
	return 0;
} 