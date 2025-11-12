#include<bits/stdc++.h>
using namespace std;
namespace myk{
	const int N=1e5+5;
	int T,n,ab[3],b[N];
	struct yes{
		int d[3],fg;
	}a[N];
	bool cmp(int x,int y){
		return x>y;
	}
	void main(){
		cin>>T;
		while(T--){
			cin>>n;
			long long ans=0;
			for(int i=1;i<=n;i++){
				int mx=-1,jl=0;
				for(int j=0;j<3;j++){
					cin>>a[i].d[j];
					if(mx<a[i].d[j]){
						mx=a[i].d[j];
						jl=j;
					}
				}
				a[i].fg=jl;
				ans+=mx;
				ab[jl]++;
			}
			int wg=-1;
			for(int i=0;i<3;i++)
				if(ab[i]>n/2)wg=i;
			if(wg!=-1){
				int ct=0;
				for(int i=1;i<=n;i++)
					if(a[i].fg==wg){
						int mx=-1;
						for(int j=0;j<3;j++)
							if(j!=wg)mx=max(mx,a[i].d[j]); 
						b[++ct]=mx-a[i].d[wg];
					}
				sort(b+1,b+1+ct,cmp);
				for(int i=1;i<=ab[wg]-n/2;i++)ans+=b[i];
			}
			cout<<ans<<"\n";
			for(int i=0;i<3;i++)ab[i]=0;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	myk::main();
	return 0;
}
