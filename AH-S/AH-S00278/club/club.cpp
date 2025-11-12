#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][4],b[N],wz[N],p[N],n;
queue<int>Q;
int add()
{
	int s=0,cnt=0;
	memset(wz,0,sizeof(wz));
	memset(p,0,sizeof(p));
	while(!Q.empty()){
		wz[++cnt]=Q.front();
		Q.pop();
	}
	for(int i=cnt;i>=1;i--){
		Q.push(wz[i]);p[wz[i]]=1;
	}
	for(int i=1;i<=n;i++){
		if(p[i])s+=a[i][1];
		else s+=a[i][2];
	}
	return s;
}
int main()
{
	int t;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int m,pa,pb,ans=0;
		cin>>n;
		m=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		//A
		pa=0;
		for(int i=1;i<=n;i++){
			for(int j=2;j<=3;j++){
				if(a[i][j]!=0)pa=1;
			}
		}
		if(!pa){
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+1+n);
			for(int i=n;i>n/2;i--)ans+=b[i];
		}
		else{
			//B
			pb=0;
			for(int i=1;i<=n;i++){
				if(a[i][3]!=0)pb=1;
			}
			if(!pb){
				for(int i=1;i<=m+1;i++){
					int w;
					while(!Q.empty())Q.pop();
					for(int j=i;j<=m+i-1;j++)Q.push(j);
					while(!Q.empty()&&Q.front()<=n){
						if(Q.size()==m)ans=max(ans,add());
						w=Q.front();
						if(Q.size()==m)Q.pop();
						if(w==n)w=Q.front(),Q.pop();
						Q.push(w+1);
					}
				}
			}
		}
		
		cout<<ans<<'\n';
	}
	return 0;
}
