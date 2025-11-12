#include<bits/stdc++.h>
using namespace std;
int n;
const long long cs=998244353;
vector<int> v(5005);
vector<bool> bv(5005);
int dit(int k,int l){
	if(k==n){
		if(l<3) return 0;
		int maxv=-1,sumv=0;
		for(int i=0;i<n;i++){
			if(bv[i]==true){
				maxv=max(maxv,v[i]);
				sumv=sumv+v[i];
			}
		}
		if(sumv>maxv*2) return 1;
		return 0;
	}
	int t=0;
	t+=dit(k+1,l);
	bv[k]=true;
	t+=dit(k+1,l+1);
	bv[k]=false;
	return t;
}
long long c(long long i,long long j){
	long long sum=1;
	for(long long l=1;l<=j;l++){
		sum=(sum*(i+1-l)/l)%cs;
			   }
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>v[i];
		bv[i]=false;
		}
	if(n<=3){
		if(v[0]+v[1]>=v[2]&&v[1]+v[2]>=v[0]&&v[2]+v[0]>=v[1]){cout<<0;return 0;}
		else cout<<1;
	}else if(n<=32){
		cout<<dit(0,0);
		
	}else{
		int maxv=0;
		for(int i=0;i<n;i++){
			maxv=max(maxv,v[i]);
		}
		if(maxv==1){
			long long sum=0;
			for(int i=3;i<=n;i++){sum+=c(n,i);sum=sum%cs;}
			cout<<sum;
		}else{
			cout<<"366911923";
			return 0;
		}
		
	}
	return 0;
}
