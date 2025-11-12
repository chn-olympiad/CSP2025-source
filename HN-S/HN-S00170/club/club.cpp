#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int T,n;
struct Node{
	int id,a,b,c;
}A[N];
bool cmp(Node x,Node y){
	if(x.a==y.a){
		if(x.b==y.b){
			return x.c>y.c;
		}
		return x.b>y.b;
	}
	return x.a>y.a;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int ans=0,cnt=0;
		int cnt1=0,cnt2=0,cnt3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			A[i].id=0;
			cin>>A[i].a>>A[i].b>>A[i].c;
		}
		sort(A+1,A+n+1,cmp);
		for(int i=1;i<=n;i++){
			cnt=0;
			if(A[i].a==0){
				cnt++;
			}
			if(A[i].b==0){
				cnt++;
			}
			if(A[i].c==0){
				cnt++;
			}
			if(cnt==2){
				if(A[i].b==0&&A[i].a!=0&&A[i].c==0){
					if(cnt1<n/2){
						cnt1++;
						ans+=A[i].a;
					A[i].id=1;
					}	
				}
				if(A[i].b!=0&&A[i].a==0&&A[i].c==0){
					
					if(cnt2<n/2){
						cnt2++;
						ans+=A[i].b;
						A[i].id=2;
					}
				}
				if(A[i].b==0&&A[i].a==0&&A[i].c!=0){
					if(cnt3<n/2){
						cnt3++;
						ans+=A[i].c;
						A[i].id=3;
					}
				}
			}
		}
			for(int i=1;i<=n;i++){
				if(A[i].id==0){
					if(A[i].a>A[i].b&&A[i].a>A[i].c){
						if(cnt1<n/2){
							ans+=A[i].a;
							cnt1++;
						}
						else{
							if(A[i].b>A[i].c){
								if(cnt2<n/2){
									ans+=A[i].b;
									cnt2++;
								}
							}		
							else{
								ans+=A[i].c;
								cnt3++;							
							}
						}
					}
					else if(A[i].b>A[i].a&&A[i].b>A[i].c){
						if(cnt2<n/2){
							ans+=A[i].b;
							cnt2++;
						}
						else{
							if(A[i].a>A[i].c){
								if(cnt1<n/2){
									ans+=A[i].a;
									cnt1++;									
								}
							}
							else{
								ans+=A[i].c;
								cnt3++;							
							}
						}
					}
					else if(A[i].c>A[i].a&&A[i].c>A[i].b){
						if(cnt3<n/2){
							ans+=A[i].c;
							cnt3++;
						}
						else{
							if(A[i].b>A[i].a){
								if(cnt2<n/2){
									ans+=A[i].b;
									cnt2++;
								}
							}
							else{
								ans+=A[i].a;
								cnt1++;							
							}
						}
					}
				}
			}

		cout<<ans<<endl;
	}
   return 0;
}

