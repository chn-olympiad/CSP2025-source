#include<bits/stdc++.h>
using namespace std;

int t,n;
struct mr{
	int x,y,z;
	int cz,bm;
};

bool cmp(mr x,mr y){
	return x.cz<y.cz; 
}

int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		long long cnt=0;
		mr m[100005];
		int a=0,b=0,c=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>m[i].x>>m[i].y>>m[i].z;
			int maxx=max(max(m[i].x,m[i].y),m[i].z),ma;
			if(maxx==m[i].x) m[i].bm=1,a++,ma=max(m[i].y,m[i].z);
			else if(maxx==m[i].y) m[i].bm=2,b++,ma=max(m[i].z,m[i].x);
			else m[i].bm=3,c++,ma=max(m[i].y,m[i].x);	
			m[i].cz=maxx-ma,cnt+=maxx;
		}
		sort(m+1,m+1+n,cmp),n/=2;
		int d=max(a,max(b,c))-n;
		if(a>n){
			for(int i=1;i<=n*2;i++)
				if(d==0) break;
				else if(m[i].bm==1) cnt-=m[i].cz,d--;	 
		}else if(b>n){
			for(int i=1;i<=n*2;i++)
				if(d==0) break;
				else if(m[i].bm==2) cnt-=m[i].cz,d--;
		}else if(c>n){
			for(int i=1;i<=n*2;i++)
				if(d==0) break;
				else if(m[i].bm==3) cnt-=m[i].cz,d--;
		}
		cout<<cnt<<"\n";
	}
	return 0;
}






