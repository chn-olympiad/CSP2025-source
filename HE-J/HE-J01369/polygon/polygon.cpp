#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
long long n,ans,cs=0;
void kill(long long all,long long *b,long long maxb,long long mxb,long long d){
	long long cx=0;
	for(int i=n;i>=1;i--){
		if(b[i]==-1) continue;
		if(i!=mxb){
			cs++;
			cx=i;
			break;
		}
	}
	for(int i=d;i<=n;i++){
		if(b[i]==-1) continue;
//		if(i!=mxb) cx=i;
//		cout<<"i:"<<i<<" a:"<<all-b[i]<<" b:"<<(i==mxb?b[cx]*2:maxb*2)<<" ans:"<<ans<<endl;
		if(!((i!=mxb&&all-b[i]<=maxb*2)||(i==mxb&&all-b[i]<=b[cx]*2))) ans=(ans+1)%mod;
		long long bi=b[i];
		b[i]=-1;
		if(i!=mxb){
			cx=i;
			kill(all-bi,b,maxb,mxb,i);
		}else{
			kill(all-bi,b,b[cx],cx,i);
		}
		b[i]=bi;
		cx++;
		if(i!=mxb&&all-b[i]<=maxb*2) i==mxb;
		
	}
	return;
}
long long sum=0,a[5050];
bool tp=true;
int main(){
	freopen("polygon.in","r",stdin),freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(tp&&a[i]!=1) tp=false; 
		sum+=a[i];
	}
//	if(tp){
//		cout<<pow(2,n-1);
//		return 0;
//	}
	sort(a+1,a+n+1);
	if(sum>a[n]*2) ans++;
	kill(sum,a,a[n],n,1);
	cout<<ans;
	return 0;
}//期望得分 40,O(2^{n-1})
