#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct s{
	int i;
	long long l;
	bool operator < (const s&a) const {
		return a.l<l;
	}
};
long long a[N],b[N],c[N];
long long c1=0,c2=0,c3=0,cnt=0,n;
long long xa[N],xb[N],xc[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		c1=c2=c3=cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]>=b[i]&&a[i]>=c[i]){
				c1++;
				xa[c1]=i;
				cnt+=a[i];
			}else if(b[i]>=a[i]&&b[i]>=c[i]){
				c2++;
				xb[c2]=i;
				cnt+=b[i];
			}else{
				c3++;
				xc[c3]=i;
				cnt+=c[i];
			}
		}
		if(c1>n/2){
			int t=c1-(n/2);
			priority_queue<s> q;
			for(int i=1;i<=c1;i++){
				q.push({i,a[xa[i]]-max(b[xa[i]],c[xa[i]])});
			}
			for(int i=1;i<=t;i++){
				s now=q.top();
				q.pop();
				cnt-=now.l;
			}
		}else if(c2>n/2){
			int t=c2-(n/2);
			priority_queue<s> q;
			for(int i=1;i<=c2;i++){
				q.push({i,b[xb[i]]-max(a[xb[i]],c[xb[i]])});
			}
			for(int i=1;i<=t;i++){
				s now=q.top();
				q.pop();
				cnt-=now.l;
			}
		}else if(c3>n/2){
			int t=c3-(n/2);
			priority_queue<s> q;
			for(int i=1;i<=c3;i++){
				q.push({i,c[xc[i]]-max(b[xc[i]],a[xc[i]])});
			}
			for(int i=1;i<=t;i++){
				s now=q.top();
				q.pop();
				cnt-=now.l;
			}
		}
		cout<<cnt<<endl;
	}
    return 0;
}
