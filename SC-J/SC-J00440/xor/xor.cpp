#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+10;
int a[N],d[N],c[N];
vector<int> t[N];
set<pair<int,int> > s;
struct dui{
	int l,r;
}f[N];
bool cmp(dui x,dui y){
	return x.r<y.r;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i],d[i]=a[i],d[i]^=d[i-1];
	for(int i=0;i<=n;i++) t[d[i]].push_back(i);
    for(int i=0;i<=n;i++) c[i]=d[i],c[i]^=k;
    for(int i=0;i<=n;i++)
        for(auto x:t[c[i]]){
        	if(x>i){
        		s.insert(make_pair(i+1,x));
        		break;
			}
		}
	int j=0;
    for(auto x:s) f[++j].l=x.first,f[j].r=x.second;
    sort(f+1,f+j+1,cmp);
    int sum=0,nr=0;
    for(int i=1;i<=j;i++)
    	if(f[i].l>nr)
    	    sum++,nr=f[i].r;
	cout<<sum;
	return 0;
}