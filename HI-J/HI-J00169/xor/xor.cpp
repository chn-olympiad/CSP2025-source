#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],cnt;
struct node{
	int l,r;
};
vector<node>v;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=2;i<=n;i++)a[i]^=a[i-1];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((a[j]^a[i-1])==k){
				v.push_back({i,j});
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<v.size();j++){
			if(v[j].l==i){
				cnt++,i=v[j].r+1;
			}
		}
	}
	printf("%d",cnt);
	return 0;
}
