#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
int n,m;
string s;
int c[510];
int f[1<<18][18];
void add(int&x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=18){
		string&ssa=s;
		f[0][0]=1;
		for(int s=0;s<(1<<n);s++){
			int siz=0;
			for(int i=0;i<n;i++){
				if((s>>i)&1)siz++;
			}
			for(int i=0;i<=n;i++){
				if(f[s][i]==0)continue;
				//cout<<"f:"<<s<<" "<<i<<" "<<f[s][i]<<endl;
				for(int j=1;j<=n;j++){
					if((s>>(j-1))&1)continue;
					int ns=s|(1<<(j-1));
					if(i<c[j]&&ssa[siz+1]=='1'){
						add(f[ns][i],f[s][i]);
					}
					else{
						add(f[ns][i+1],f[s][i]);
					}
				}
			}
		}
		int res=0;
		//n-i>=m
		//i<=n-m
		for(int i=0;i<=n-m;i++){
			add(res,f[(1<<n)-1][i]);
		}
		cout<<res<<"\n";
		return 0;
	}
	return 0;
}
