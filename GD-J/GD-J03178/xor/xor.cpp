#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
	int l,r;
};
bool cmp(node x,node y){
	if(x.r!=y.r) return x.r<y.r;
	else return x.l<y.l;
}
int n,k,sum[500005],a[500005],cnt=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	vector<node> qj;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1) sum[i]=sum[i-1]^a[i];
		else sum[i]=a[i];
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			int x=sum[r]^sum[l-1];
			if(x==k){
				qj.push_back({l,r});
			}
		}
	}
	sort(qj.begin(),qj.end(),cmp);
	int end=qj[0].r;
	for(int i=1;i<qj.size();i++){
		if(qj[i].l>end){
			end=qj[i].r;
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
