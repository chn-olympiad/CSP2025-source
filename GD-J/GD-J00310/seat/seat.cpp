#include<bits/stdc++.h> 
using namespace std;
int a[105]={0};
bool cmp(int x,int y){
	if(x<=y)return 0;
	else return 1;
}int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,s,R,id;
	cin>>n>>m>>R;
	a[0]=R;
	s=n*m;
	for(int i=1;i<s;i++){
		cin>>a[i];
	}sort(a,a+s,cmp);
	for(int i=0;i<s;i++){
		if(a[i]==R){
			id=i+1;
			break;
		}
	}long long lie;
	if(id%n==0){
		lie=id/n;
		if(lie%2){
			cout<<lie<<' '<<n;
		}else cout<<lie<<' '<<1;
		return 0;
	}lie=id/n+1;
	if(lie%2){
		cout<<lie<<' '<<id%n;
	}else cout<<lie<<' '<<n-id%n+1;
	return 0;
}
