#include<bits/stdc++.h>

using namespace std;
int t;
const int N=1e5+10;
struct test{
	int d1;
	int d2;
	int d3;
	int maxx;
	int midd;
	int num;
};
bool cmp(test x,test y){
	if(x.maxx==y.maxx){
		return x.midd>=y.midd;
	}
	return x.maxx>y.maxx;
}
long long ans[7];
test a[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		memset(a,0,sizeof(a));
		int n;
		cin>>n;
		int dn[4]={0,0,0,0};
		for(int i=1;i<=n;i++){
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
			a[i].maxx=max(a[i].d1,max(a[i].d2,a[i].d3));
			a[i].midd=a[i].d1+a[i].d2+a[i].d3-a[i].maxx-min(a[i].d1,min(a[i].d2,a[i].d3));
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].d1==a[i].maxx){
				a[i].num=1;
			}else if(a[i].d2==a[i].maxx){
				a[i].num=2;
			}else if(a[i].d3==a[i].maxx){
				a[i].num=3;
			}
			if(dn[a[i].num]<(n/2)){
				dn[a[i].num]++;
				ans[k]+=a[i].maxx;
			}else{
				int midnum;
				if(a[i].d1==a[i].midd){
					midnum=1;
				}else if(a[i].d2==a[i].midd){
					midnum=2;
				}else if(a[i].d3==a[i].midd){
					midnum=3;
				}
				dn[midnum]++;
				ans[k]+=a[i].midd;
			}
		}
	}
	for(int k=1;k<=t;k++){
		cout<<ans[k]<<endl;
	}
	return 0;
}

