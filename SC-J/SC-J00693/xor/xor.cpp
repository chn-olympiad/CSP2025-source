#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s[500005],ss;
int l,r;
int xx(int x,int z){
	int p[25],q[25],ans[25],n_=1,m_=1;
	long long sum=0;
	memset(p,0,sizeof(p));
	memset(q,0,sizeof(q));
	memset(ans,0,sizeof(ans));
	while(x>0){
		p[n_]=x%2;
		n_++;
		x/=2;
	}
	while(z>0){
		q[m_]=z%2;
		m_++;
		z/=2;
	}
	int nn=max(n_,m_);
	for(int i=1;i<nn;i++){
		if(p[i]!=q[i]){
			ans[i]=1;
		}
		else{
			ans[i]=0;
		}
	}
	for(int i=1;i<=nn;i++){
		sum+=(1<<(i-1))*ans[i];
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[1]=a[1];
		if(i!=1){
			s[i]=xx(a[i],s[i-1]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(xx(s[j],s[i])==k){
				ss++;
				if((i+1>=l&&i+1<=r)||(j>=l&&j<=r)){
					if(j-i<r-l){
						l=i;
						r=j;
					}
					ss--;
				}
				else{
					l=i+1;
					r=j;
				}
			}
		}
	}
	cout<<ss;
	return 0;
}