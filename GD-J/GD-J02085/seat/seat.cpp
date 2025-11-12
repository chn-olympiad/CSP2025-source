#include<bits/stdc++.h>
using namespace std;
int a[110];
bool pai(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	cin>>a[1];
	int num=a[1];
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+n*m+1,pai);
	for(int i=1;i<=n*m;i++)
		if(a[i]==num){
			num=i;
			break;
		}
	cout<<(num-1)/m+1<<" ";
	num=num%(2*m);
	if(num<=m)cout<<num;
	else cout<<2*m-num+1;
	return 0;
} 
