#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freoepn("seat.out","w",stdout);
	int n,m;//n为行 m为列
	cin>>n>>m;
	int sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	int fs=a[1];
	sort(a+1,a+1+sum,cmp);
	int now=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[now]==fs){
					cout<<i<<" "<<j;
				}
				now++;	
			}
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(a[now]==fs){
					cout<<i<<" "<<j;
				}
				now++;
			}
		}
	}
	return 0;
}
