#include<bits/stdc++.h>
using namespace std;
int T,n,sum,m,maxx,cx,cy,cz,p,ans,b;
struct stu{
	int x;
	int y;
	int z;
	int s;
};
bool cmp(stu x,stu y){
	return x.s>y.s;
}
int main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
		stu a[100010];
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			b=max(a[i].x,a[i].y);
			a[i].s=max(b,a[i].z);
		}sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			m=max(a[i].x,a[i].y);
			p=min(a[i].x,a[i].y);
			maxx=max(m,a[i].z);
			if(maxx==a[i].z)cz++;
			else if(maxx==m&&m==a[i].x)cx++;
			else if(maxx==m&&m==a[i].y)cy++;
			if(cx<=n/2&&cy<=n/2&&cz<=n/2){
			sum+=maxx;
		}else if(cx>n/2||cy>n/2||cz>n/2){
			if(maxx==m){
				maxx=p;
			}else if(maxx==a[i].z){
				maxx=m;
			}
			sum+=maxx;
		}
		ans=max(ans,sum);
		}
		cout<<ans<<endl;
		sum=0;
		maxx=0;
		m=0;
		cx=0;
		cy=0;
		cz=0;
		p=0;
		ans=0;
	}
    return 0;
}
