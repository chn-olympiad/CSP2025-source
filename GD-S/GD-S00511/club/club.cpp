#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int a,b,c;
}ap[100005];
int cnt[4];
bool cmp(node x,node y){
	return x.a>y.a;
}
bool cmp2(node x,node y){
	return x.b>y.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int l=1;l<=t;l++){
		bool flag_A=1;
		cin >> n; 
		for(int i=1;i<=n;i++){
			cin >> ap[i].a>>ap[i].b>>ap[i].c;
			if(ap[i].b!=0){
				flag_A=0;
			}
		}
		if(n==2){
			int ans=0,man=-1;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i==j){
						continue;
					}else{
						ans=0;
						if(i==1){
							ans+=ap[1].a;
						}
						if(i==2){
							ans+=ap[1].b;
						}
						if(i==3){
							ans+=ap[1].c;
						}
						if(j==1){
							ans+=ap[2].a;
						}
						if(j==2){
							ans+=ap[2].b;
						}
						if(j==3){
							ans+=ap[2].c;
						}
						man=max(man,ans);
					}
				}
			}
			cout << man;
		}else if(flag_A){
			sort(ap+1,ap+1+n,cmp);
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=ap[i].a;
			}
			cout << ans;
		}else{
			sort(ap+1,ap+1+n,cmp);
			int ans1=0;
			for(int i=1;i<=n/2;i++){
				ans1+=ap[i].a;
			}
			for(int i=n/2+1;i<=n;i++){
				ans1+=ap[i].b;
			} 
			sort(ap+1,ap+1+n,cmp2);
			int ans2=0;
			for(int i=1;i<=n/2;i++){
				ans2+=ap[i].b;
			}
			for(int i=n/2+1;i<=n;i++){
				ans2+=ap[i].a;
			} 
			cout << max(ans1,ans2);
		}	
	}	
	return 0;
} 
