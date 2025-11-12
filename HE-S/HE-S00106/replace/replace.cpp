#include<bits/stdc++.h>
using namespace std;

int t,n,maxn;
int a,b,c;
int fval[100005];
int h[5];
int ans;
int cnt;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q,q1,q2;

int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cnt=0;
		ans=0;
		memset(fval,0,sizeof(fval));
		memset(h,0,sizeof(h));
		cin>>n;
		maxn=n/2;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
//			for(int i=1;i<=n;i++){
//				cout<<fval[i];
//			}
			if(a>=b&&a>=c){
				if(h[1]<=maxn){
					q.push(make_pair(a,i));
					h[1]++;
					ans+=a;
					if(b>c){
						fval[i]=a-b;
					}else{
						fval[i]=a-c;
					}
				}else{
					int f=q.top().first;
					int s=q.top().second;
					if(a-fval[s]>f){
						q.pop();
						q.push(make_pair(a,i));
						ans+=a;
						ans-=fval[s];
						if(b>c){
							fval[i]=a-b;
						}else{
							fval[i]=a-c;
						}
					}else{
						if(b>c){
							h[2]++;
							q1.push(make_pair(b,i));
							fval[i]=b-c;
							ans+=b;
						}else{
							h[3]++;
							q2.push(make_pair(c,i));
							fval[i]=c-b;
							ans+=c;
						}
					}
				}
			}
			if(b>=a&&b>=c){
				if(h[2]<=maxn){
					h[2]++;
					q1.push(make_pair(b,i));
					ans+=b;
					if(a>c){
						fval[i]=b-a;
					}else{
						fval[i]=b-c;
					}
				}else{
					int f=q1.top().first;
					int s=q1.top().second;
					if(b-fval[s]>f){
						q1.pop();
						q1.push(make_pair(b,i));
						ans+=b;
						ans-=fval[s];
						if(a>c){
							fval[i]=b-a;
						}else{
							fval[i]=b-c;
						}
					}else{
						if(a>c){
							h[1]++;
							q.push(make_pair(a,i));
							ans+=b;
							fval[i]=a-c;
						}else{
							h[3]++;
							q2.push(make_pair(c,i));
							ans+=c;
							fval[i]=c-a;
						}
					}
				}
			}
			if(c>=a&&c>=b){
				if(h[3]<=maxn){
					h[3]++;
					q2.push(make_pair(c,i));
					ans+=c;
					if(a>b){
						fval[i]=c-a;
					}else{
						fval[i]=c-b;
					}
				}else{
					int f=q2.top().first;
					int s=q2.top().second;
					if(c-fval[s]>f){
						q2.pop();
						q2.push(make_pair(c,i));
						ans+=c;
						ans-=fval[s];
						if(b>c){
							fval[i]=c-b;
						}else{
							fval[i]=c-a;
						}
					}else{
						if(b>a){
							h[2]++;
							q1.push(make_pair(b,i));
							ans+=b;
							fval[i]=b-a;
						}else{
							h[3]++;
							q.push(make_pair(a,i));
							ans+=a;
							fval[i]=a-b;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
