#include <bits/stdc++.h>
using namespace std;
int a[110];
int n,m,l,h,pos;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=sum;i++){
		if(a[i]==t){
			pos=i;
		}
	}
	if(pos%n==0){
		l=pos/n;
		if(l%2==0){
			h=1;
		} 
		else{
			h=n;
		}
	}
	else{
		l=pos/n+1;
		if(l%2==1){
			h=pos%n;
		}
		else h=n-pos%n+1;
	}
	cout<<l<<" "<<h<<"\n";
	return 0;
}