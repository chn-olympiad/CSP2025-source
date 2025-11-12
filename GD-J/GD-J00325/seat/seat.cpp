#include<bits/stdc++.h>
#define int long long
using namespace std;
int num[1000005],n,m;

struct node{
	int s,id;
}a[100005];
bool cmp(node a,node b){
	return a.s>b.s;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].s;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int nd;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){nd=i;break;}
	}
	int ans=nd/n+(nd%4>0);
	cout<<ans<<" ";
	if(ans%2==0){
		if(nd%n==0){
			cout<<1;
		}else{
			cout<<n-(nd%n)+1;
		}
	}else{
		if(nd%n==0){
			cout<<n;
		}else{
			cout<<nd%n;
		}
		
	}
	return 0;
}
