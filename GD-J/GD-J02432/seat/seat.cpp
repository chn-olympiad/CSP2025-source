#include<iostream>
#include<algorithm>
using namespace std;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int i;
	for(i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+i+1,cmp);
	int now=1;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(a[now]==r){
					cout<<i<<" "<<j;
					return 0;
				}
				now++;
			}
		}
		else {
			for(int j=1;j<=n;j++){
				if(a[now]==r){
					cout<<i<<" "<<j;
					return 0;
				}
				now++;
			}
		}
	}
	return 0;
}
