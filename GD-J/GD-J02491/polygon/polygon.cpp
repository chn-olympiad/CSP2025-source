#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;

int n,ans,t;
int a[N];
int v[N];

void dfs(int s,int p,int ma,int an){
	
	if(s>2*ma){
		bool fl=0;
		for(int i=1;i<=ans;i++){
			if(v[i]==an) {
				fl=1;
			}
		}
		if(fl) {
			
		}
		else{
			t=an;
//			while(t){
//				cout<<t%10<<"+";
//				t/=10;
//			}
//			cout<<" "<<s<<"\n";
			ans++;
			v[ans]=an;
		}
	}
	if(p>n) return;
	dfs(s+a[p],p+1,max(ma,a[p]),an*10+p);
	dfs(s,p+1,ma,an); 
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	dfs(0,1,0,0);
	cout<<ans;
	return 0;
} 

