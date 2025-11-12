#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int n,m,a[500005],s,maxn;
long long x[3005];
struct stc{
	int l,r;
	bool operator< (const stc &rhs) const{
		return r<rhs.r;
	}
}q[3005];
void try_50(){
	for (int i=1;i<=n;i++){
		cin>>a[i];
		x[i]=x[i-1]^a[i];
	}
	int cnt=0,R=0;
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			if ((x[j]^x[i-1])==m){
				q[++cnt].l=i;q[cnt].r=j;
			}
		}
	}
	sort(q+1,q+1+cnt);
	for (int i=1;i<=cnt;i++){
		if (q[i].l>R){
			s++;R=q[i].r;
		}
	}
	cout<<s;
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	if (n<=1000) try_50();
	else{
		for (int i=1;i<=n;i++){
			cin>>a[i];
			maxn=max(maxn,a[i]);
		}
		if (maxn<=1){
			if (m==1){
				int cnt_1=0;
				for (int i=1;i<=n;i++){
					if (a[i]==1) cnt_1++;
				}
				cout<<cnt_1;
			}
			else if (m==0){
				int cnt_0=0;
				for (int i=1;i<=n;i++){
					if (a[i]==0) cnt_0++;
				}
				for (int i=1;i<=n;i++){
					if (a[i]==1&&a[i-1]==1) cnt_0++,i++;
				}
				cout<<cnt_0;
			}
			else cout<<0;
		}
	}
	return 0;
}
