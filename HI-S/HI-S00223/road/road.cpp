#include <iostream>
#include <algorithm>
using namespace std;
struct road{
	int a,b,v;
}in[100010];
bool cmp(road a,road b){
	return a.v<b.v;
}
int p,n,m,q,in1,in2[100010],tree[10010];
long long ans;
int find(int a){
	if(a==tree[a]) return a;
	return find(tree[a]);
}
void merge(int a,int b){
	int c=find(a),d=find(b);
	if(c==d) return;
	tree[d]=c;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++) tree[i]=i;
	for(p=1;p<=m;p++){
		cin>>in[p].a>>in[p].b>>in[p].v;
	}
	for(int i=1;i<=q;i++){
		cin>>in1;
		for(int j=1;j<=n;j++){
			cin>>in2[j];
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(j!=k){
					in[p++].a=j,in[p].b=k,in[p].v=in2[j]+in2[k]+in1;
				}
			}
		}
	}
	p--;
	sort(in+1,in+p+1,cmp);
	for(int i=1;i<=p;i++){
		int A=find(in[i].a),B=find(in[i].b);
		if(A==B) continue;
		else merge(A,B),ans+=in[i].v;
	}
	cout<<ans<<endl;
	return 0;
}

