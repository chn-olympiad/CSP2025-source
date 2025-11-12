#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long t,n,f1,f2,f3,ans;
struct xx{
	long long ii,x1,x2,x3,fi1,fi2,fi3,x;
}d[N];
int cmd(xx a,xx b){
	return a.x>b.x;
}
void maxn1(long long a,long long b,long long c){
	long long max_n=max(max(a,b),c);
	if(a==max_n && b==max_n){
		f1=1;
		f2=2;
		return;
	}
	else if(a==max_n && c==max_n){
		f1=1;
		f2=3;
		return;
	}
	else if(b==max_n && c==max_n){
		f1=2;
		f2=3;
		return;
	}
	else if(a==max_n){
		if(b>=c){
			f1=1;
			f2=2;
			return;
		}
		else{
			f1=1;
			f2=3;
			return;
		}
	}
	else if(b==max_n){
		if(a>=c){
			f1=2;
			f2=1;
			return;
		}
		else{
			f1=2;
			f2=3;
			return;
		}
	}
	else if(c==max_n){
		if(a>=b){
			f1=3;
			f2=1;
			return;
		}
		else{
			f1=3;
			f2=3;
			return;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout)
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		int cnt1=0,cnt2=0,cnt3=0,ed=n/2;
		for(long long i=1;i<=n;i++){
			cin>>d[i].x1>>d[i].x2>>d[i].x3;
			maxn1(d[i].x1,d[i].x2,d[i].x3);
			if(f1==1 && f2==2){
				d[i].x=d[i].x1-d[i].x2;
				d[i].fi1=1;
				d[i].fi2=2;
				d[i].fi3=3;
			}
			if(f1==2 && f2==3){
				d[i].x=d[i].x2-d[i].x3;
				d[i].fi1=2;
				d[i].fi2=3;
				d[i].fi3=1;
			}
			if(f1==1 && f2==3){
				d[i].x=d[i].x1-d[i].x3;
				d[i].fi1=1;
				d[i].fi2=3;
				d[i].fi3=2;
			}
		}
		sort(d+1,d+n+1,cmd);
		for(long long i=1;i<=n;i++){
			if(d[i].fi1==1){
				if(cnt1!=ed){
					ans+=d[i].x1;
					cnt1++;
					continue;
				}
				else{
					if(d[i].fi2==2){
						if(cnt2!=ed){
							ans+=d[i].x2;
							cnt2++;
							continue;
						}
						else{
							ans+=d[i].x3;
							cnt3++;
							continue;
						}
					}
					else{
						if(cnt3!=ed){
							ans+=d[i].x3;
							cnt3++;
							continue;
						}
						else{
							ans+=d[i].x2;
							cnt2++;
							continue;
						}
					}
				}
			}
			if(d[i].fi1==2){
				if(cnt2!=ed){
					ans+=d[i].x2;
					cnt2++;
					continue;
				}
				else{
					if(d[i].fi2==1){
						if(cnt1!=ed){
							ans+=d[i].x1;
							cnt1++;
							continue;
						}
						else{
							ans+=d[i].x3;
							cnt3++;
							continue;
						}
					}
					else{
						if(cnt3!=ed){
							ans+=d[i].x3;
							cnt3++;
							continue;
						}
						else{
							ans+=d[i].x1;
							cnt1++;
							continue;
						}
					}
				}
			}
			if(d[i].fi1==3){
				if(cnt3!=ed){
					ans+=d[i].x3;
					cnt3++;
					continue;
				}
				else{
					if(d[i].fi2==1){
						if(cnt1!=ed){
							ans+=d[i].x1;
							cnt1++;
							continue;
						}
						else{
							ans+=d[i].x2;
							cnt2++;
							continue;
						}
					}
					else{
						if(cnt2!=ed){
							ans+=d[i].x2;
							cnt2++;
							continue;
						}
						else{
							ans+=d[i].x1;
							cnt1++;
							continue;
						}
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
