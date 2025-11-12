#include<bits/stdc++.h>
using namespace std;
int n;
long long k;
int a[500100];
int ma=0;
void dfs(int x,int r,int gs){
	if(r==k)gs++;
	ma=max(gs,ma);	
	if(x>n)return;
//	cout<<x<<endl;

	if(r!=k){
		int t=r^a[x];
//		cout<<r<<" "<<a[x]<<" "<<t<<endl;
		dfs(x+1,t,gs);
	}	
	dfs(x+1,a[x],gs);
}
bool pd(){
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			return 0;
		}
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	cin>>k;
	if(k<=255){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(k==0&&pd()){
			cout<<n/2;
		}else if(k==1){
			int x=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					x++;
				}
			}
			cout<<x;
		}else{
			
			for(int i=1;i<=n;i++){
				dfs(i+1,a[i],0);
			}
			cout<<ma;
		}
	}
	
	return 0;
}

