#include<bits/stdc++.h>
using namespace std;
int n,maxn=0,sum,gs,c,d[10010];
struct node{
	int id,z;
}a[10100];
long long ans;
bool b[10010];
bool cmp(node x,node y){
	if(x.z<y.z||x.z==y.z&&x.id<y.id) return true;
	else return false;
}
void dfs(){
	if(sum>maxn*2&&gs>=3){
		ans++;
	
//		for(int i=1;i<=gs;i++){
//			cout<<d[i]<<" ";
//		}
//		cout<<endl;
	}
		for(int i=1;i<=n;i++){
			if(!b[a[i].id]&&a[i].id>d[gs]){
				c=maxn;
				if(a[i].z>maxn){
					maxn=a[i].z;
				}
				sum+=a[i].z;
				gs++;
				d[gs]=a[i].id;
				b[a[i].id]=true;
				dfs();
				sum-=a[i].z;
				d[gs]=0;
				gs--;
				b[a[i].id]=false;
				if(a[i].z==maxn){
					maxn=c;
				}
			}
		}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].z;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	dfs();
	cout<<(long long)ans%998244353;
	return 0;
} 
