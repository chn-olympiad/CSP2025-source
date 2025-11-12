#include<bits/stdc++.h>
using namespace std;
int n/*hang*/,m/*lie*/;
int a[110];
bool cmp(int&a,int&b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	a[0]=a[1];
	sort(a+1,a+n*m+1,cmp);
	int now_=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==a[0]){
			now_=i;
			break;
		}
	}
	int x=(now_/n)+1;
	if(now_%n==0){
		x=now_/n;
	}
	cout<<x<<" ";
	if(x%2==1){
		cout<<now_-(x-1)*n;
	}else{
		cout<<n-(now_-(x-1)*n)+1;
	}
	return 0;
}