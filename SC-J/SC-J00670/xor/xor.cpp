#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
long long n,h,k,sum[5*N],a[5*N],ans;
struct caoi{
	int lt,rt;
}p[1013144];
bool cmp(caoi sl,caoi sr){
	if(sl.rt!=sr.rt)return sl.rt<sr.rt;
	return sl.lt<sr.lt;
}
int main(){
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j+i-1<=n;j++){
			int r=j+i-1;
			int x=sum[j-1],y=sum[r];
			int cnt=y^x;
			if(cnt==k){
				p[++h].lt=j;
				p[h].rt=r;
			}
		}
	}
	sort(p+1,p+1+h,cmp);
	int tail=0;
	for(int i=1;i<=h;i++){
		if(tail==0){
			tail=p[i].rt;
			++ans;
			continue;
		}
		if(p[i].lt>tail){
			tail=p[i].rt;
			++ans;
		}
	}
	cout<<ans;
	return 0;
}