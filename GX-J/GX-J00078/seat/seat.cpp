#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int n,m,a[100005];
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int ans=n*m;
	int cnt=a[0];
	sort(a,a+ans,cmp);
	for(int i=0;i<ans;i++){
		if(a[i]==cnt){
			cnt=i+1;
		}
	}
	int x=cnt/n;
	int y=cnt%n;
	if(y>0){
		x++;
		if(x%2==0){
			cout<<x<<" "<<n-y+1;
		}else{
			cout<<x<<" "<<y;
		}
	}else{
		if(x%2==0){
			cout<<x<<" "<<1;
		}else{
			cout<<x<<" "<<n;
		}
	}
	return 0;
}
