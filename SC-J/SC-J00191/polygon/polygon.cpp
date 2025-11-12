#include<bits/stdc++.h>
using namespace std;
/*我只是一个蒟蒻*/
struct nn{
	long long s;
	long long maxx;
	long long l;
}a[4000000]; 
long long n,m,q=1,s,w[1008],bj=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>w[i];
		if(w[i]!=1)bj=0;
	}
	if(bj){
		n-=2;
		int i=1;
		while(n--){
			s+=i%998244353;
			s%=998244353; 
			i++;
		}
		cout<<s;
	}
	else{
		for(long long i=1;i<=n;i++){
			int t=q;
			for(long long j=1;j<=t;j++){
				a[++q].s=a[j].s+w[i];
				a[q].l=a[j].l+1;
				a[q].maxx=max(a[j].maxx,w[i]);
				if(a[q].s>a[q].maxx*2&&a[q].l>=3)s++,s%=998244353;
			}
		}
		cout<<s;		
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
} 