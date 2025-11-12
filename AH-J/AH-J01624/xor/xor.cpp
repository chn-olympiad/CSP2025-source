#include<bits/stdc++.h>
using namespace std;
struct stu{
	int l,r;
}b[500005];
long long n,a[500005],f[500005],k,m,t,d;
bool cmp(stu x,stu y){
	if(x.r!=y.r){
		return x.r<y.r;
	}
	return x.l<y.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		 cin>>a[i];
		 f[i]=f[i-1]^a[i];
	}
	long long cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((f[j]^f[i-1])==k){
				m++;
				b[m].l=i;
				b[m].r=j;
			}
		}
	}
	sort(b+1,b+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(b[i].l>d){
			cnt++;
			t=b[i].l;
			d=b[i].r;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
