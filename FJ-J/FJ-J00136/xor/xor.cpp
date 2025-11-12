#include<bits/stdc++.h>
using namespace std;
struct qj{//区间 
	int l,r;//该区间的左右端点 
};
vector<qj> b;
bool cmp(qj x,qj y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int x=a[i];
		qj y;
		if (x==k) {
			y={i,i};
			b.push_back(y);
		}
		for(int j=i+1;j<=n;j++){
			x=x^a[j];
			if (x==k) {
				y={i,j};
				b.push_back(y);
			}
		}
	}
	//for(int i=0;i<b.size();i++) printf("%d %d\n",b[i].l,b[i].r);
	
	sort(b.begin(),b.end(),cmp);
	
	int last=0,ans=0;
	for(int i=0;i<b.size();i++){
		if(b[i].l>last){
			ans++;
			last=b[i].r;
		}
	}
	printf("%d",ans);
	return 0;
}
