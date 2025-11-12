#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	int now=1;
	for(int i=1;i<=n;i++){
		if(i%2){
			for(int j=1;j<=m;j++){
				if(a[now]==x){
					cout<<i<<" "<<j;
					return 0;
				}
				now++;
			}
		}else{
			for(int j=m;j>=1;j--){
				if(a[now]==x){
					cout<<i<<" "<<j;
					return 0;
				}
				now++;
			}
		}
	}
	return 0;
}
