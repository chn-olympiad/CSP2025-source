#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int a[10005],sum[10005],n,k;
struct qujian{
	int l,r;
}q[10005];

bool cmp(qujian x,qujian y){
	return x.r<y.r;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	int t=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((sum[j]^sum[i-1])==k){
				t++;
				q[t].l=i;
				q[t].r=j;
			}
		}
	}
	sort(q+1,q+t+1,cmp);
	int tmp=0,sum=0;
	for(int i=1;i<=t;i++){
		if(q[i].l>tmp){
			tmp=q[i].r;
			sum++;
		}
	}
	cout<<sum<<endl;
	return 0;
}
