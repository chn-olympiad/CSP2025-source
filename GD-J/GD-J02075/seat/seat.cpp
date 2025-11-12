#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N];
int n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	int ans=a[1];
	int op=0;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		
		if(ans==a[i]){
			op=i;
			break;
		}
	}
	if(op<=n){
		cout<<1<<" "<<op<<endl;
		return 0;
	}
	int y=op/n;
	if(op%n==0)y--;
	int x=0;
	if(y%2==0)x=op-y*n;
	else x=n-(op-y*n)+1;
	cout<<y+1<<" "<<x<<endl;
	return 0;
} 
