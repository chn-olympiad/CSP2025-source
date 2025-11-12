#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int id;
	int cj;
}a[10010];
bool cmp(node a,node b){
	return a.cj>b.cj;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int mu_qy;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].cj;
		if(i==1){
			mu_qy=a[i].cj;
		}
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int q_qy,l=1,r=n*m;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[mid].cj==mu_qy){
			q_qy=mid;
			break;
		}else if(a[mid].cj<mu_qy){
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	if(q_qy%n==0){
		if((q_qy/n)%2==1){
			cout<<q_qy/n<<" "<<n<<endl;
		}else{
			cout<<q_qy/n<<" "<<1<<endl;
		}
	}else{
		if((q_qy/n+1)%2==1){
			cout<<q_qy/n+1<<" "<<q_qy%n<<endl;
		}else{
			cout<<q_qy/n+1<<" "<<n-q_qy%n+1<<endl;
		}
	}
	return 0;
}
