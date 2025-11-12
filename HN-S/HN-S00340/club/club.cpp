#include<bits/stdc++.h>
using namespace std;
struct node{
	int o,t1,t2;
}a[100005];
bool cmp(node x,node y){
	if(x.o!=y.o){
		return x.o>y.o;
	}else{
		if(x.t1!=y.t1){
			return x.t1>y.t1;
		}else{
			return x.t2>y.t2;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,sum=0,b=0,c=0,d=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].o>>a[i].t1>>a[i].t2;
		}
		sort(a+1,a+n+1,cmp);
		int o1=n/2,t3=n/2,t4=n/2;
		for(int i=1;i<=n;i++){
			if(a[i].o>a[i].t1&&a[i].o>a[i].t2&&o1>0){
				o1--;
				sum+=a[i].o;
			}else if(a[i].t1>a[i].o&&a[i].t1>a[i].t2&&t3>0){
				t3--;
				sum+=a[i].t1;
			}else if(a[i].t2>a[i].o&&a[i].t2>a[i].t1&&t4>0){
				t4--;
				sum+=a[i].t2;
			}
		}
		cout<<sum<<endl;
	} 
}
