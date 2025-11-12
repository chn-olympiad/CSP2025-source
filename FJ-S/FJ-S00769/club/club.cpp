#include <bits/stdc++.h>
using namespace std;
int t;
const int N=1e5+7;
int n,book[5],a,b,c,maxn,maxn2,maxn3,d;
long long ans;
struct rp{
	int a,b,c,d;
}k;
bool operator<(rp a,rp b){
	return a.a-a.b>b.a-b.b;
}
priority_queue<rp>  q1,q2,q3,kong;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie();
	cin >> t;
	while(t--){
		memset(book,0,sizeof(book));ans=0;
		q3=kong;q1=kong,q2=kong;
		cin >> n;
		int nn=n/2;
		for(int i=1;i<=n;i++){
			cin >> a >> b >> c;
			maxn=max(a,max(b,c));
			if(maxn==a){
				maxn2=max(b,c),maxn3=min(b,c);
				if(maxn2==b) d=2;
				else d=3;
				k.a=maxn,k.b=maxn2,k.c=maxn3,k.d=d;
				if(book[1]==nn){
					rp h=q1.top();
					if(h.a-h.b<maxn-maxn2){
						q1.pop();
						q1.push(k);
						if(h.d==2) q2.push(h);
						else q3.push(h);
						ans+=maxn,ans-=h.a-h.b;
					}else if(d==2) q2.push(k),ans+=maxn2;
					else q3.push(k),ans+=maxn2;
				}else ans+=maxn,q1.push(k),book[1]++;
			}else if(maxn==b){
				maxn2=max(c,a),maxn3=min(c,a);
				if(maxn2==c) d=3;
				else d=1;
				k.a=maxn,k.b=maxn2,k.c=maxn3,k.d=d;
				if(book[2]==nn){
					rp h=q2.top();
					if(h.a-h.b<maxn-maxn2){
						q2.pop();
						q2.push(k);
						if(h.d==3) q3.push(h);
						else q1.push(h);
						ans+=maxn,ans-=h.a-h.b;
					}else if(d==3) q3.push(k),ans+=maxn2;
					else q1.push(k),ans+=maxn2;
				}else ans+=maxn,q2.push(k),book[2]++;
			}else{
				maxn2=max(a,b),maxn3=min(a,b);
				if(maxn2==a) d=1;
				else d=2;
				k.a=maxn,k.b=maxn2,k.c=maxn3,k.d=d;
				if(book[3]==nn){
					rp h=q3.top();
					if(h.a-h.b<maxn-maxn2){
						q3.pop();
						q3.push(k);
						if(h.d==2) q2.push(h);
						else q1.push(h);
						ans+=maxn,ans-=h.a-h.b;
					}else if(d==2) q2.push(k),ans+=maxn2;
					else q1.push(k),ans+=maxn2;
				}else ans+=maxn,q3.push(k),book[3]++;
			} 
		}
		cout << ans<< "\n"; 
	} 
	return 0; 
} 
