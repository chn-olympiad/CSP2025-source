#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Node{
	int num;
	int id;
};
Node a[150];
bool cmp(Node x,Node y){
	return x.num>y.num;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){ 
		cin>>a[i].num;
		a[i].id=i; 
	}
	sort(a+1,a+1+n*m,cmp);
	int k=0;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			k=i;
		}
	}
	int ans_m=k%m;
	int ans_n=k/m;  
	if(ans_m==0){
		ans_m=m;
	}else{
		ans_n+=1;
	}
	if(ans_n%2==0){
		ans_m=m-ans_m+1;
	}
	cout<<ans_n<<" "<<ans_m;
	return 0;
}