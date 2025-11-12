#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],gsa=0,m=0,p=0;
long long n,k;
long long get(int x,int y){
	return b[y] xor b[x-1];
}struct li{
	long long l,r,w;
}l[500005];
bool cmp(li x,li y){
	if(x.r==y.r){
		return x.l>y.l;
	}return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1] xor a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(get(i,j)==k){
				m++;
				l[m].l=i;
				l[m].r=j;
			}
		}
	}sort(l+1,l+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(p>n){
			break;
		}if(l[i].l>=p){
			p=l[i].r+1;
			gsa++;
		}
	}
	cout<<gsa;
	return 0;
}