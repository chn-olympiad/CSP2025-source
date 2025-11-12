#include<bits/stdc++.h>
using namespace std;
int a[110];
int n,m;
bool cmp(int a,int b){
	return a>b;
}
int find(int b){
	int l=0,r=n*m+1,mid;
	while(l+1<r){
		mid=(l+r)/2;
		if(a[mid]<b){
			r=mid;
		}
		else{
			l=mid;
		}
	}
	return l;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int y=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=find(y);
	int ans1=x/m+(x%m?1:0);
	x%=m;
	int ans2;
	if(ans1%2==1){
		ans2=x;
		if(!x){
			ans2=m;
		}
	}
	else{
		ans2=m-x+1;
		ans2%=m;
		if(ans2==0){
			ans2=m;
		}
	}
	cout<<ans1<<" "<<ans2<<"\n";
	return 0;
}
