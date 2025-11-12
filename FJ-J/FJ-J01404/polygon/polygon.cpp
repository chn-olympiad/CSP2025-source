#include <bits/stdc++.h>
using namespace std;
using i64=long long;
int n;
int a[5005];
const int mod=998244353;
i64 qcm(i64 a,i64 p){
	i64 ans=1;
	while(p){
		if(p&1){
		    ans*=a;
		    ans%=mod;
	    }
	    a*=a;
	    p>>=1;
		a%=mod;
	}
	
	return ans%mod;
}
//No graph,No tree?
//64pts in theory
//f[i][j] stand for consider the previous i sticks and the total length is j;
//in special,if i=1ori=2 the real answer is 0 but in f,let it 1 or the vaild answer.
//so we can calculate the answer more convenient. 
//using pre_sum to accerlate the caculation.
//we must know how many triangles is vaild,then we try to add edges.
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int tmp=0;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		tmp=max(tmp,a[i]);
	}
	int cnt=0;
	if(n<=20){//count all subset
		int S=(1<<n)-1;
		for(int T=0;T<=S;T++){
			int sum=0,mx=0;
			if(__builtin_popcount(T)<3) continue;
			for(int i=0;i<=n;i++){
				int j=i+1;
				if((1<<i)&T) {
					sum+=a[j],mx=max(mx,a[j]);
			    }
			}
			if(mx*2<sum) cnt++,cnt%=mod;
		}
		cout << cnt << endl;
		//return 0;
	}else if(tmp==1){//所有大于等于3的都是合法解答 
		cout << (qcm(2,n)-1-n-((n-1)*n)/2+mod)%mod <<endl;
	}
	return 0;
} 
/*int k=4;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		k+=a[i];
		
	}
	sort(a+1,a+n+1);//let a[i] be sorted;
	for(int i=1;i<=n;i++){
		if(i==1)h[a[i]]+=1;if(i==1) continue;
		for(int j=k;j>=2*a[i]+1;j--){
			f[j]+=f[j-a[i]];
			f[j]+=g[j-a[i]];
		}
		for(int j=k;j>=a[i]+1;j--){//处理“两边形” 
			g[j]+=h[j-a[i]];
		}
		h[a[i]]+=1;
		
		
		for(int t=1;t<=k;t++){
			cout << h[t] << ' '; 
		}cout << endl;
		for(int t=1;t<=k;t++){
			cout << g[t] << ' '; 
		}cout << endl;
		for(int t=1;t<=k;t++){
			cout << f[t] << ' '; 
		}cout << endl;
		cout << endl;
	}
	long long ans=0;
	for(int i=1;i<=k;i++){
		ans+=f[i];
	}
	cout << ans << endl;
*/
