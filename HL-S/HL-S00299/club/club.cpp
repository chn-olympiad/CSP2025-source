#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int T;
int n,cnt[10];
struct Mem{
	int a1,a2,a3,max1,max2,max3;
}mem[N];
//bool cmp(Mem x,Mem y){
//	if(x.max1==y.max1){
//		if(x.max2==y.max2) return x.max3>y.max3;
//		return x.max2>y.max2; 
//	}
//	return x.max1>y.max1;
//}
bool cmp(Mem x,Mem y){
	return x.max1>y.max1;
}
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q[5];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++){
			cin>>mem[i].a1>>mem[i].a2>>mem[i].a3;
			if(mem[i].a1>=mem[i].a2){
				if(mem[i].a2>=mem[i].a3){
					mem[i].max1=mem[i].a1; 
					mem[i].max2=mem[i].a2; 
					mem[i].max3=mem[i].a3; 
				}
				else{
					if(mem[i].a1>=mem[i].a3){
						mem[i].max1=mem[i].a1; 
						mem[i].max2=mem[i].a3; 
						mem[i].max3=mem[i].a2; 					
					}
					else{
						mem[i].max1=mem[i].a3; 
						mem[i].max2=mem[i].a1; 
						mem[i].max3=mem[i].a2; 
					} 	
				}
			}
			else{
				if(mem[i].a2>=mem[i].a3){
					if(mem[i].a1>=mem[i].a3){
						mem[i].max1=mem[i].a2; 
						mem[i].max2=mem[i].a1; 
						mem[i].max3=mem[i].a3; 
					}
					else{
						mem[i].max1=mem[i].a2; 
						mem[i].max2=mem[i].a3; 
						mem[i].max3=mem[i].a1; 
					}
				}
				else{
					mem[i].max1=mem[i].a3; 
					mem[i].max2=mem[i].a2; 
					mem[i].max3=mem[i].a1; 
				}
			}
		} 
		sort(mem+1,mem+n+1,cmp);
		int num=n/2,ans=0;
		for(int i=1;i<=n;i++){
			if(mem[i].max1==mem[i].a1){
				if(cnt[1]<num){
					ans+=mem[i].max1;
					cnt[1]++;
				}
				else{
					if(mem[i].max2==mem[i].a2){
						if(cnt[2]<num){
							ans+=mem[i].max2;
							cnt[2]++;
						}
						else{
							ans+=mem[i].max3;
							cnt[3]++;
						}
					}
					else{
						if(cnt[3]<num){
							ans+=mem[i].max2;
							cnt[3]++;
						}
						else{
							ans+=mem[i].max3;
							cnt[2]++;
						}
					}
				}
			}
			else if(mem[i].max1==mem[i].a2){
				if(cnt[2]<num){
					ans+=mem[i].max1;
					cnt[2]++;
				}
				else{
					if(mem[i].max2==mem[i].a1){
						if(cnt[1]<num){
							ans+=mem[i].max2;
							cnt[1]++;
						}
						else{
							ans+=mem[i].max3;
							cnt[3]++;
						}
					}
					else{
						if(cnt[3]<num){
							ans+=mem[i].max2;
							cnt[3]++;
						}
						else{
							ans+=mem[i].max3;
							cnt[1]++;
						}
					}
				}
			}
			else if(mem[i].max1==mem[i].a3){
				if(cnt[3]<num){
					ans+=mem[i].max1;
					cnt[3]++;
				}
				else{
					if(mem[i].max2==mem[i].a1){
						if(cnt[1]<num){
							ans+=mem[i].max2;
							cnt[1]++;
						}
						else{
							ans+=mem[i].max3;
							cnt[2]++;
						}
					}
					else{
						if(cnt[2]<num){
							ans+=mem[i].max2;
							cnt[2]++;
						}
						else{
							ans+=mem[i].max3;
							cnt[1]++;
						}
					}
				}
			}
		}
		cout<<ans<<'\n'; 
	}
	return 0;
}
