#include<bits/stdc++.h>
using namespace std;
int T;
const int N=1e5+1;
struct node{
	int a,b,c;
	int ma;
};
struct nodde{
	int z;
	int b;
	int c;
};
nodde zw;
bool cmp(nodde x,nodde y){
	return x.c>y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	zw.z=0;
	zw.b=0;
	cin>>T;
	while(T--){
		size_t n;
		cin>>n;
		vector<node> b;
		vector<nodde> v1;
		vector<nodde> v2;
		vector<nodde> v3;
		int aa,bb,cc;
		int sum=0;
		for(size_t i=0;i<n;i++){
			cin>>aa>>bb>>cc;
			node x;
			x.a=aa;
			x.b=bb;
			x.c=cc;
			x.ma=max(x.a,max(x.b,x.c));
			b.push_back(x);
			nodde xx;
			xx.b=i;
			xx.z=b[i].ma;
			if(b[i].ma==b[i].a) {
				xx.c=x.a-max(x.c,x.b);
				v1.push_back(xx);
			}
			else if(b[i].ma==b[i].b){
				xx.c=x.b-max(x.a,x.c);
				v2.push_back(xx);
			}
			else {
				xx.c=x.c-max(x.a,x.b);
				v3.push_back(xx);
			}
			sum+=b[i].ma;
		}
		if(v1.size()<=n/2&&v2.size()<=n/2&&v3.size()<=n/2){
			cout<<sum<<'\n';
			continue;
		}
		sort(v1.begin(),v1.end(),cmp);
		sort(v2.begin(),v2.end(),cmp);
		sort(v3.begin(),v3.end(),cmp);
		
		if(v1.size()>n/2){
			for(size_t i=n/2;i<v1.size();i++){
				sum-=v1[i].c;
			}
		}
		else if(v2.size()>n/2){
			for(size_t i=n/2;i<v2.size();i++){
				sum-=v2[i].c;
			}
		}
		else if(v3.size()>n/2){
			for(size_t i=n/2;i<v3.size();i++){
				sum-=v3[i].c;
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
