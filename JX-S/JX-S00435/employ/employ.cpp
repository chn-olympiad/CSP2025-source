#include<bits/stdc++.h>
using namespace std;
int n,m;
string a;
int yu[1000005];
int c[1000005];
long long ans;
bool op[1000005];
void jk(int p,int k,int qw){
	if(p==n){
		if(qw>=m){
			++ans;
			ans %= 998244353;
		}
		return ;
	}
	for(int i=1;i<=n;++i){
		if(op[i]==0){
			if(yu[i]==0){
				op[i] = 1;
				jk(p+1,k+1,qw);
				op[i] = 0;
			}
			else{
				if(k>=c[i]){
					op[i] = 1;
					jk(p+1,k+1,qw);
					op[i] = 0;
				}
				else{
					op[i] = 1;
					jk(p+1,k,qw+1);
					op[i] = 0;
				}
			}
			
		}
	}
	
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	int l1=a.size();
	for(int i=0;i<l1;++i)
		yu[i+1] = a[i]-'0';
	for(int i=1;i<=n;++i)
		cin>>c[i];
	jk(0,0,0);
	cout<<ans;
	return 0;
}
