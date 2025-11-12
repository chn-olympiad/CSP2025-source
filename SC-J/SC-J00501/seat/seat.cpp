#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int n,m,num,x=1,y=1;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	num=1;
	for(int i=2,j=i;i<=n*m;i++){
		cin>>a[i];
		j=i;
		while(a[j]>a[j-1]&&j!=1){
			if(j-1==num){
				num=j;
			}
			swap(a[j-1],a[j]);
		}
	}
	while(num>n){
		num=num-n;
		x++;
	}
	y=num;
	if(x%2==0){
		cout<<x<<" "<<m-y+1;
	}
	else cout<<x<<" "<<y;
	return 0;
}