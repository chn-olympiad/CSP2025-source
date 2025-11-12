#include<bits/stdc++.h>
using namespace std;
using ll=long long; 
const int N=1048576+10;
bool A=1;
int n,k,a[N],pre[N],qi,ans,a0,a1,ans1;
struct qj{
	int l,r;
}q[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	const int kk=k;
	cin>>a[1];
	if(a[1]==1) a1++;
	else if(a[1]==0) a0++;
	pre[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
		if(a[i]!=1) A=0;
		if(a[i]==1) a1++;
		else if(a[i]==0) a0++;
		
		//cout<<pre[i]<<endl;
	} 
	//cout<<a0<<' '<<a1<<endl;
	if(A==1&&k==0){
		cout<<n<<endl;
		return 0;
	}else if(k==0) {
		cout<<n;
		return 0;
	}else if(k==1&&a0+a1==n){
		int tmp=a[1];
//		for(int i=2;i<=n;i++){
//			tmp^=a[i];
//			if(tmp){
//				ans1++,i++,tmp=a[i];
//			}
//		} 
	//	cout<<66;
		ans1=max(a0,a1);
		cout<<ans1<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int found=kk^pre[i];
		//cout<<i<<' '<<kk<<' '<<pre[i]<<' ';
		//cout<<found<<endl;
		int x=lower_bound(pre+i,pre+n+1,found)-pre;
		if(x==i) q[qi++].l=i,q[qi-1].r=x;
		else if(x==found) q[qi++].l=i-1,q[qi-1].r=x;
		//cout<<q[qi-1].l<<' '<<q[qi-1].r<<endl;
	}
	int frr=q[0].r;
	if(qi>=1) ans=1;
	else {
		cout<<0;
		return 0;
	}
	for(int i=1;i<qi;i++){
		while(q[i].l<=frr&&i<qi) i++;
		ans++,frr=q[i].r;
	}
	cout<<ans<<endl;
	return 0;
}
