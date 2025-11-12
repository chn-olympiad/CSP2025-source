#include<bits/stdc++.h>
using namespace std;


const int N=110;
int n,m;
int a[N];

int R;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				cnt++;
				if(a[cnt]==R){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}else{
			for(int j=m;j>=1;j--){
				cnt++;
				if(a[cnt]==R){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
