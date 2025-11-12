#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001],sum;
bool cmp(int a,int b){
	return a>b;
}
int x=1,y=1,R;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i]<<" ";
//	}
	for(int i=1;i<=n*m;i++){
		if(R!=a[i]){
			if((x==n&&sum%2==0)||(x==1&&sum%2==1)){
				if(sum%2==0) x=n;
				else x=1;
				sum++;
				y++;
			}else{
				if(sum%2==0) x++;
				else x--;
			}
		}else{
			break;
		}
//		cout<<y<<" "<<x<<'\n';
	}
	cout<<y<<" "<<x;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
