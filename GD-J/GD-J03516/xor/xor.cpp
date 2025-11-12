#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int r[maxn],R[maxn];
int a[maxn],sum[maxn];
int cfsl[maxn];
struct N{
	int l,r;
	bool fl;
}cnt[maxn];
int ANS;
bool cmp(int a,int b) {return a<b;}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) sum[i]=a[i];
		else sum[i]=sum[i-1]^a[i];
	}
	int sl=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j+=i){
			if((sum[j]^sum[j-i])==k){
				sl++;
				cnt[sl]={j-i+1,j,1};
				r[j]++;
			}
		}
	}
	int lj=0;
	for(int i=1;i<=n;i++){
		lj+=r[i];
		R[i]=lj;
	}
	for(int i=1;i<=sl;i++){
		cfsl[i]=R[cnt[i].r]-R[cnt[i].l-1]-1;
		if(cfsl[i]==0){
			ANS++;
			cnt[i].fl=0;
		}
	}
	sort(cfsl+1,cfsl+sl+1,cmp);
	int jsq=0;
	for(int i=1;i<=sl;i++){
		if(cnt[i].fl==0) continue;
		if(jsq==0){
			ANS++;
			jsq+=cfsl[i]+1;
		}
		jsq--;
	}
	cout<<ANS;
}
