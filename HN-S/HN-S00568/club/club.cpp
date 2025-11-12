#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,ans,xx,yy,zz;
priority_queue<int> a1,a2,a3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		while(a1.size())a1.pop();
		while(a2.size())a2.pop();
		while(a3.size())a3.pop();
		xx=0,yy=0,zz=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			if(x>=y&&x>=z){
				xx++;ans+=x;
				a1.push(min(x-y,x-z)*-1);
			}else if(y>=x&&y>=z){
				yy++;ans+=y;
				a2.push(min(y-x,y-z)*-1);
			}else if(z>=y&&z>=x){
				zz++;ans+=z;
				a3.push(min(z-y,z-x)*-1);
			}
		}
		//cout<<ans<<endl;;
		if(xx>n/2){
			while(xx!=n/2){
				ans+=a1.top();
				a1.pop();
				xx--;
			}
		}else if(yy>n/2){
			while(yy!=n/2){
				ans+=a2.top();
				a2.pop();
				yy--;
			}
		}else if(zz>n/2){
			while(zz!=n/2){
				ans+=a3.top();
				a3.pop();
				zz--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


