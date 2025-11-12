#include <bits/stdc++.h>
using namespace std;
long long n,ans=0,awa,i,a=1,qwq,b=1,x[7834];
vector<long long> stick;
vector<long long> use;
int main(){
	fill(x,x+7834,0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	i = 3; //i为多边形边数 
	for(int i=0;i<n;i++){
		scanf("%lld",&awa);
		stick.push_back(awa);
	}
	sort(stick.begin(),stick.end());
	for(int p=0;p<n;p++){
		x[p]=p;
	}
	while(i <= n){ //i为多边形边数 
		a=1;b=1;
		for(int j=1;j<n;j++){
			a*=j;
		}
		for(int j=1;j<i;j++){
			b*=j;
		}
		qwq = a/b; //排列组合数
		int o=i;
		while(qwq--){
			long long sum=0,l=i-1;
			while(o--){
				use.push_back(stick[x[o]]);
			}
			sort(use.begin(),use.end());
			x[l]++; //第e个数位取到的木棍长度的索引 
			for(int y=0;y<use.size();y++){
				sum+=use[y];
			}
			if(sum > (use[use.size()-1]*2)) ans++; //是多边形 
			//printf("%lld %lld\n",sum,(use[use.size()-1]*2));
			for(int e=l;e>0;e--){
				if(x[e] == n-e){
					x[e] == 0;
					x[e-1]++;
				}
			}
		}
		for(int p=0;p<n;p++){
			x[p]=p;
		} //i个长度的取完了 
		i++;
	}
	printf("%lld",ans);
	return 0;
}
