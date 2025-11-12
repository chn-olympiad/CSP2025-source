#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
struct node{
	ll a,b,c;
}x[N];
struct e{
	ll a,b;
}y[N];
bool cmp(node d,node e){
//	if(a.c!=b.c){
//		return a.c<b.c;
//	}else if(a.b!=b.b){
//		return a.b<b.b;
//	}else {
//		return a.a<b.a;
//	}
	return max(d.a,max(d.b,d.c))>max(e.a,max(e.b,e.c));
}
bool cmp1(e a,e b){
	return a.b>b.b;
}
bool vis[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	ll t;
	cin>>t;
	while(t--){
		ll n,sum=0,sum1=0,sum2=0,sum3=0,sum4=0,sum5=0;
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			y[i].a=x[i].a,y[i].b=x[i].a-x[i].b;
			if(!x[i].b){
				sum4++;
			}
			if(!x[i].c){
				sum5++;
			}
		}
		sort(x+1,x+1+n,cmp);
		if(sum4==n && sum5==n){
			for(ll i=1;i<=n/2;i++){
				sum+=x[i].a;
			}
			cout<<sum<<'\n';
			continue;
		}else if(sum5==n){
//			sort(y+1,y+1+n,cmp1);
//			for(int i=1;i<=n;i++){
//				if(y[i].b>0 && sum2<n/2){
//					sum+=y[i].a+y[i].b;
//					sum2++;
//				}else if(y[i].b<0 && sum1<n/2){
//					sum1++;
//					sum+=y[i].a;
//				}else{
//					if(sum1==n/2){
//						sum+=y[i].a+y[i].b;
//					}else if(sum2==n/2){
//						sum+=y[i].a;
//					}else{
//						vis[i]=1;
//					}
//				}
////				cout<<y[i].b<<" ";
//			}
//			for(int i=1;i<=n;i++){
//				if(vis[i]){
//					vis[i]=0;
//					if(sum1==n/2){
//						sum+=y[i].a+y[i].b;
//					}else if(sum2==n/2){
//						sum+=y[i].a;
//					}else{
//						if(sum1<n/2){
//							sum1++;
//							sum+=y[i].a;
//						}else{
//							sum2++;
//							sum+=y[i].a+y[i].b;
//						}
//					}
//				}
//			}
			for(ll i=1;i<=n;i++){
				if(x[i].a==x[i].b){
					vis[i]=1;
					continue;
				}
//				cout<<x[i].a<<" "<<x[i].b<<'\n';
				if((x[i].a>x[i].b && sum1<n/2) || sum2==n/2){
					sum+=x[i].a;
					sum1++;
				}else {
					sum2++;
					sum+=x[i].b;
				}
			}
			for(ll i=1;i<=n;i++){
				if(vis[i]){
					vis[i]=0;
					sum+=x[i].a;
				}
			}
			cout<<sum<<'\n';
			continue;
		}
		for(ll i=1;i<=n;i++){
			ll j=x[i].a,k=x[i].b,l=x[i].c;
//			cout<<j<<" "<<k<<" "<<l<<'\n';
			if(j>=k && j>=l && sum1<n/2-1){
				sum1++;
				sum+=j;
//				cout<<1<<'\n';
			}else if(k>=j && k>=l && sum2<n/2-1){
				sum2++;
				sum+=k;
//				cout<<2<<'\n';
//				cout<<k<<" "<<sum<<'\n';
			}else if(l>=j && l>=k && sum3<n/2-1){
				sum3++;
				sum+=l;
//				cout<<3<<'\n';
			}else{
				if(i!=n){
					if(sum1==n/2-1){
						if((x[i].b>x[i].c && sum2<n/2) || sum3==n/2){
							if(x[i+1].a+x[i].b>=x[i].a+max(x[i+1].b,x[i+1].c)){
								sum1++;
								sum2++;
								sum+=x[i+1].a+x[i].b;
								i++;
							}else{
								sum1++;
								sum+=x[i].a;
							}
						}else {
							if(x[i+1].a+x[i].c>=x[i].b+max(x[i+1].b,x[i+1].c)){
								sum1++;
								sum3++;
								sum+=x[i+1].a+x[i].c;
								i++;
							}else{
								sum1++;
								sum+=x[i].a;
							}
						}
					}else if(sum2==n/2-1){
						if((x[i].a>x[i].c && sum1<n/2) || sum3==n/2){
							if(x[i+1].b+x[i].a>=x[i].b+max(x[i+1].a,x[i+1].c)){
								sum1++;
								sum2++;
								sum+=x[i+1].b+x[i].a;
								i++;
							}else{
								sum2++;
								sum+=x[i].b;
							}
						}else {
							if(x[i+1].b+x[i].c>=x[i].b+max(x[i+1].a,x[i+1].c)){
								sum2++;
								sum3++;
								sum+=x[i+1].a+x[i].c;
								i++;
							}else{
	//					cout<<i<<'\n';
								sum2++;
								sum+=x[i].b;
							}
						}
					}else if(sum3==n/2-1){
						if((x[i].a>x[i].b && sum1<n/2) || sum2==n/2){
							if(x[i+1].c+x[i].a>=x[i].c+max(x[i+1].a,x[i+1].b)){
								sum1++;
								sum3++;
								sum+=x[i+1].c+x[i].a;
								i++;
							}else{
								sum3++;
								sum+=x[i].c;
							}
						}else {
							if(x[i+1].c+x[i].b>=x[i].c+max(x[i+1].a,x[i+1].b)){
								sum2++;
								sum3++;
								sum+=x[i+1].c+x[i].b;
								i++;
							}else{
								sum1++;
								sum+=x[i].c;
							}
						}
					}
				}
				else if(sum1>=n/2){
					if(k>=l){
						sum2++;
						sum+=k;
//				cout<<12<<'\n';
					}else{
						sum3++;
						sum+=l;
//				cout<<13<<'\n';
					}
				}
				else if(sum2>=n/2){
					if(j>=l){
						sum1++;
						sum+=j;
//				cout<<21<<'\n';
					}else{
						sum3++;
						sum+=l;
//				cout<<23<<'\n';
					}
				}else{
					if(j>=k){
						sum1++;
						sum+=j;
//				cout<<31<<'\n';
					}else{
						sum2++;
						sum+=k;
//				cout<<32<<'\n';
					}
				}
			}
//		cout<<sum1<<'\n';
		}
		cout<<sum<<'\n';
	}
	return 0;
}
