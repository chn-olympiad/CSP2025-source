#include<bits/stdc++.h>
using namespace std;
struct qujian{
	int l,r,len;
};
bool cmp(qujian a,qujian b){
	return a.len<b.len;
}
int a[500005];
qujian b[1000000];
int check[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int qqq=0;
	for(int i=0;i<n;i++){
		long long sum=0;
		for(int j=i;j<n;j++){
			sum=sum^a[j];
			if(sum==k){
				b[qqq].l=i;
				b[qqq].r=j;
				b[qqq].len=j-i+1;
				qqq++;
			}
		}
	}
	int ans=0;
	sort(b,b+qqq,cmp);
	for(int i=0;i<qqq;i++){
		int f=0;
		for(int j=b[i].l;j<=b[i].r;j++){
			if(check[j]==1){
				f=1;
				break;
			}
		}
		if(f)	continue;
		ans++;
		for(int j=b[i].l;j<=b[i].r;j++){
			check[j]=1;
		}
	}
	cout<<ans;
	return 0;
}