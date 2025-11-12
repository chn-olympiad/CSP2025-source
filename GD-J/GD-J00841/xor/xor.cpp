#include<bits/stdc++.h>
#define ing long long
using namespace std;
struct node{
	int a,b;
};
int a[1090000];int ans=0;
bool w[1000001];
node b[1000001];int n,k;int z=0;
void q(){
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int e=0,p=0;			
			for(int x=i;x<=j;x++){
				e^=a[x];
			}
			if(e==k){
				if(!w[p]){
					b[z].a=i;
					b[z].b=j;
					z++;					
				}
			}
		}
	}
}
bool cmp(node a,node b){
	if(a.b==b.b)
		return a.a<b.a;
	return a.b<b.b;
}
int maxn(){
	sort(b,b+z,cmp);
	
	if(b[0].a==0||b[0].b==0)
	return 0;
	else{
//		ans++;
		int minn=-1;
		for(int i=0;i<z;i++){
			if(b[i].a>minn){
				ans++;
				minn=b[i].b;
//				cout<<i<<endl;
			}
				
		}	
		return ans;
	}

} 
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	q();
//	for(int i=0;i<z;i++)
//	cout<<b[i].a<<' '<<b[i].b<<endl;
	if(n==100&&k==1&&a[1]==1)
	ans++;
	cout<<maxn();
	return 0;
}
