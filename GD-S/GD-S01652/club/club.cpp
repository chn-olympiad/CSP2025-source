#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node2{
	int num,index;
};
struct node{
	node2 b[4];
}m;
node a[N];
int cnt[4];
bool cmp1(node x,node y){
	if(x.b[1].num!=y.b[1].num){
		return x.b[1].num>y.b[1].num;
	}else if(x.b[2].num!=y.b[2].num){
		return x.b[2].num>y.b[2].num;
	}else{
		return x.b[3].num>y.b[3].num;
	}
}
bool cmp2(node2 x,node2 y){
	return x.num>y.num;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i].b[j].num;
				a[i].b[j].index=j;
			}
		}
		for(int i=1;i<=n;i++){
			sort(a[i].b+1,a[i].b+3+1,cmp2);
		}
		sort(a+1,a+n+1,cmp1);
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(cnt[a[i].b[j].index]<n/2){
					sum+=a[i].b[j].num;
					cnt[a[i].b[j].index]++;
					break;
				}
			}
		}
		cout<<sum<<endl;
		for(int i=1;i<=3;i++){
			cnt[i]=0;
		}
		for(int i=1;i<=n;i++){
			a[i]=m;
		}
	}
	return 0;
} 
