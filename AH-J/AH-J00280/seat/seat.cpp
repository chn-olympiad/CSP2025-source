#include<bits/stdc++.h>
using namespace std;
int n,m,mark,num;
int a[200];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	mark=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==mark){
			num=i;
			break;
		}
	}
	if((int(ceil(num*1.0/n)))%2==0){
		cout<<int(ceil(num*1.0/n))<<" ";
		if(num%m!=0){
			cout<<n-(num%n)+1;
		}
		else{
			cout<<1;
		}
	}
	else{
		cout<<int(ceil(num*1.0/n))<<" ";
		if(num%n==0){
			cout<<n;
		}
		else{
			cout<<num%n;
		}
	}
	return 0;
}
