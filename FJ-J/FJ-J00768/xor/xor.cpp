#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
int n,k,id;
int a[500100];
struct qujian{
	int l,r;
}b[2000100];
bool cmp(qujian x,qujian y){
	if(x.l==y.l){
		return x.r<y.r;
	}
	return x.l<y.l;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	int maxn=0,s=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		maxn=max(maxn,a[i]);
		if(a[i]==1){
			s++;
		}
	}
	if(k<=1 && maxn==1){
		if(k==1){
			cout<<s;
		}else{
			cout<<n*(n+1)/2-s;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int t=0;
		for(int j=i;j<=n;j++){
			t^=a[j];
			if(t==k){
				id++;
				b[id]={i,j};
				break;
			}
		}
	}
	sort(b+1,b+id+1,cmp);
//	cout<<"-------------------------"<<endl;
	int ans=0,t=0;
	for(int i=1;i<=id;i++){
//		printf("%lld %lld\n",b[i].l,b[i].r);
		if(b[i].r<t){
			t=b[i].r;
			continue;
		}
		if(t<=b[i].l-1){
			ans++;
			t=b[i].r;
		}
	}
	printf("%lld",ans);
	return 0;
}
