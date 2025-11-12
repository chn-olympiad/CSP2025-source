#include<bits/stdc++.h>
using namespace std;
const long long K=998244353;
long long n,a[5010],ma;
struct w{
	long long s,g;
};
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygen.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	long long an=0;	
	if(n<=20){
		sort(a+1,a+1+n);
		for(int i=3;i<=n;i++){
			queue<w>k;
			k.push((w){0,0});
			while(!k.empty()){
				w k2=k.front();
				k.pop();
				if(k2.s>a[i])an++,an%=K;
				for(int j=k2.g+1;j<i;j++){
					k.push((w){k2.s+a[j],j});
				}
			}
		}
		cout<<an;
	}
	else if(ma==1){
		for(int i=3;i<=n;i++){
			long long s=1,s2=1;
			for(int j=n;j>n-i;j--)s*=j,s2*=n-j+1;
			an+=s/s2;
			an%=K;
		}
		cout<<an;
	}
	else if(n<=500){
		sort(a+1,a+1+n);
		for(int i=3;i<=n;i++){
			queue<w>k;
			k.push((w){0,0});
			while(!k.empty()){
				w k2=k.front();
				k.pop();
				if(k2.s>a[i])an++,an%=K;
				for(int j=k2.g+1;j<i;j++){
					k.push((w){k2.s+a[j],j});
				}
			}
		}
		cout<<an;
	}
	return 0;
}

