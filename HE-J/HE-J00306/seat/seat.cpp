#include<bits/stdc++.h>
using namespace std;
int a[130];
int n,m,r,num=0;
int a1=0,a2=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	for(int i=1;i<=n*m;i++){
		if(a[i]>r){
			num++;
			a[i]=-1;
		}
	}
	a1=(num-1)%n;
	if(a1%n!=0){
		a2=(n-num)%n;
		a2++;
	}else{
		a2=num%n;
		a2++;
	}
	cout<<a1+1<<" "<<a2;
	return 0;
}
