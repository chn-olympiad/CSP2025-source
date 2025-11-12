#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+5;
long long ans;

struct q{
	int b_1,b_2,b_3;
}a[MAX];

bool cmp1(q x,q y){
	return x.b_1>y.b_1;
}

bool cmp2(q x,q y){
	return x.b_1+x.b_2+x.b_3>y.b_1+y.b_2+y.b_3;
}

void dfs(int w,int cnt_1,int cnt_2,int cnt_3,int nn,long long sum){
	if(w>nn*2){
		ans=max(ans,sum);
		return;
	}
	if(cnt_1+1<=nn){
		dfs(w+1,cnt_1+1,cnt_2,cnt_3,nn,sum+a[w].b_1);
	}
	if(cnt_2+1<=nn){
		dfs(w+1,cnt_1,cnt_2+1,cnt_3,nn,sum+a[w].b_2);
	}
	if(cnt_3+1<=nn){
		dfs(w+1,cnt_1,cnt_2,cnt_3+1,nn,sum+a[w].b_3);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int q=1;q<=t;q++){
		ans=0;
		int n,cnt_1=0,cnt_2=0,cnt_3=0;
		cin>>n;
		int nn=n/2;
		bool is_a=true;
		for(int i=1;i<=n;i++){
			cin>>a[i].b_1>>a[i].b_2>>a[i].b_3;
			if(a[i].b_3!=0||a[i].b_2!=0) is_a=false;
		}
		if(is_a==true){
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=n/2;i++) ans+=a[i].b_1;
			cout<<ans<<"\n";
		}
		else{
			if(n>=30){
				sort(a+1,a+1+n,cmp2);
			for(int i=1;i<=n;i++){
				if(a[i].b_1>=a[i].b_2&&a[i].b_1>=a[i].b_3){
					if(cnt_1+1<=nn){
						cnt_1++;
						ans+=a[i].b_1;
					}
					else if(a[i].b_2>a[i].b_3){
						if(cnt_2+1<=nn){
							cnt_2++;
							ans+=a[i].b_2;
						}
						else{
							cnt_3++;
							ans+=a[i].b_3;
						}
					}
					else{
						if(cnt_3+1<=nn){
							cnt_3++;
							ans+=a[i].b_3;
						}
						else{
							cnt_2++;
							ans+=a[i].b_2;
						}
					}
				}
				else if(a[i].b_2>=a[i].b_1&&a[i].b_2>=a[i].b_3){
					if(cnt_2+1<=nn){
						cnt_2++;
						ans+=a[i].b_2;
					}
					else if(a[i].b_1>a[i].b_3){
						if(cnt_1+1<=nn){
							cnt_1++;
							ans+=a[i].b_1;
						}
						else{
							cnt_3++;
							ans+=a[i].b_3;
						}
					}
					else{
						if(cnt_3+1<=nn){
							cnt_3++;
							ans+=a[i].b_3;
						}
						else{
							cnt_1++;
							ans+=a[i].b_1;
						}
					}
				}
				else if(a[i].b_3>=a[i].b_2&&a[i].b_3>=a[i].b_1){
					if(cnt_3+1<=nn){
						cnt_3++;
						ans+=a[i].b_3;
					}
					else if(a[i].b_2>a[i].b_1){
						if(cnt_2+1<=nn){
							cnt_2++;
							ans+=a[i].b_2;
						}
						else{
							cnt_1++;
							ans+=a[i].b_1;
						}
					}
					else{
						if(cnt_1+1<=nn){
							cnt_1++;
							ans+=a[i].b_1;
						}
						else{
							cnt_2++;
							ans+=a[i].b_2;
						}
					}
				}
			}
			cout<<ans<<"\n";
			}
			else{
				dfs(1,0,0,0,n/2,0);
				cout<<ans<<"\n";
			}
		}
	}
	return 0;
}
