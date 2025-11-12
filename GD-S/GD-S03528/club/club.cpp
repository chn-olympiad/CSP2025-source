#include<bits/stdc++.h> 
using namespace std;
const int N=1e3+5;
int T;
int n,m;
int ans;
int g[5];
struct stu{
	int val,id;
	int gr[5];
}a[N];
void dabiao(int x,int sum){
	for(int i=1;i<=3;i++){
		if(g[i]<n/2){
//			cout<<g[i];
			g[i]++;
			if(x>n)ans=max(ans,sum);
			dabiao(x+1,sum+a[x].gr[i]);
			g[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T){
		cin>>n;
		ans=0;
		g[1]=g[2]=g[3]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i].gr[j];
			}
		}
		dabiao(1,0);
		cout<<ans;
		T--;
	}
	
	return 0;
}
