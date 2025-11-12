#include<bits/stdc++.h>
using namespace std;
long long t,n;
long long tn[5];
struct sNode{
	long long ans;
	long long cnt1;
	long long cnt2;
}a1[100005],a2[100005],a3[100005],maxx,maxn;
bool cmp(sNode x,sNode y){
	return x.ans>y.ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		long long all=0;
		for(long long i=1;i<=n;i++){
			cin>>a1[i].ans>>a2[i].ans>>a3[i].ans;
			a1[i].cnt1=1;
			a2[i].cnt1=2;
			a3[i].cnt1=3;
			a1[i].cnt2=i;
			a2[i].cnt2=i;
			a3[i].cnt2=i;
		}
		tn[1]=n/2;
		tn[2]=n/2;
		tn[3]=n/2;
		sort(a1+1,a1+1+n,cmp);
		sort(a2+1,a2+1+n,cmp);
		sort(a3+1,a3+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(a1[i].ans==a2[i].ans&&a1[i].cnt2!=a2[i].cnt2){
				swap(a2[i].ans,a2[i+1].ans);
			}
			if(a2[i].ans==a3[i].ans&&a2[i].cnt2!=a3[i].cnt2){
				swap(a3[i].ans,a3[i+1].ans);
			}
			if(a1[i].ans==a3[i].ans&&a1[i].cnt2!=a3[i].cnt2){
				swap(a1[i].ans,a1[i+1].ans);
			}
			maxx.ans=a1[i].ans;
			maxx.cnt1=a1[i].cnt1;
			maxx.cnt2=a1[i].cnt2;
			if(maxx.ans<a2[i].ans){
				maxx.ans=a2[i].ans;
				maxx.cnt1=a2[i].cnt1;
			}
			if(maxx.ans<a3[i].ans){
				maxx.ans=a3[i].ans;
				maxx.cnt1=a3[i].cnt1;
			}
			if(maxx.cnt1==1){
				if(a2[i].ans>a3[i].ans){
					maxn.ans=a2[i].ans;
					maxn.cnt1=a2[i].cnt1;
				}else{
					maxn.ans=a3[i].ans;
					maxn.cnt1=a3[i].cnt1;
				}
			}else if(maxx.cnt1==2){
				if(a1[i].ans>a3[i].ans){
					maxn.ans=a1[i].ans;
					maxn.cnt1=a1[i].cnt1;
				}else{
					maxn.ans=a3[i].ans;
					maxn.cnt1=a3[i].cnt1;
				}
			}else{
				if(a2[i].ans>a1[i].ans){
					maxn.ans=a2[i].ans;
					maxn.cnt1=a2[i].cnt1;
				}else{
					maxn.ans=a1[i].ans;
					maxn.cnt1=a1[i].cnt1;
				}
			}
			if(maxn.ans+a1[i+1].ans>maxx.ans||maxn.ans+a2[i+1].ans>maxx.ans||maxn.ans+a3[i+1].ans>maxx.ans){
				maxx.ans=maxn.ans;
				maxx.cnt1=maxn.cnt1;
			}
			tn[maxx.cnt1]--;
			if(tn>=0){
				all+=maxx.ans;
			}else{
				all+=maxn.ans;
				tn[maxn.cnt1]--;
			}
		}
		cout<<all<<endl;
	}
	return 0;
}
