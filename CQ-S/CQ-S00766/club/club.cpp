#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define lp p>>1
#define rp p>>1|1
const int N=1e5+5;
//Ren5Jie4Di4Ling5%
LL T,n,x[N],y[N],z[N],a,b,c,cntx,cnty,cntz;
LL sum;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>T;
	while(T--){
		cntx=0,cnty=0,cntz=0,sum=0;
		cin>>n;
		int m1,m2,m3;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			if(a>=b){
				if(b>=c) m1=a,m2=b,m3=c;
				else{
					if(a>=c) m1=a,m2=c,m3=b;
					else m1=c,m2=a,m3=b;
				}
			}
			else{
				if(a>=c) m1=b,m2=a,m3=c;
				else{
					if(b>=c) m1=b,m2=c,m3=a;
					else m1=c,m2=b,m3=a;
				}
			}
			int d=m1-m2;
			sum+=m1;
			if(m1==a) x[++cntx]=d;
			else if(m1==b) y[++cnty]=d;
			else z[++cntz]=d;
			
		}
		int cntt=max(cnty,max(cntx,cntz));
		if(cntt>n/2){
			if(cntx==cntt){
				sort(x+1,x+1+cntx);
				for(int i=1;i<=cntt-(n/2);i++)
					sum-=x[i];
			}
			else if(cnty==cntt){
				sort(y+1,y+1+cnty);
				for(int i=1;i<=cntt-(n/2);i++)
					sum-=y[i];
			}
			else{
				sort(z+1,z+1+cntz);
				for(int i=1;i<=cntt-(n/2);i++)
					sum-=z[i];
			}
		}
		cout<<sum<<"\n";
	}
	
	return 0;
} 
