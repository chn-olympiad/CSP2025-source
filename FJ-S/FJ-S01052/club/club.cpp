#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
struct stu{
	int index;
	int a1;
	int a2;
	int a3;
};
stu l1[100010];
stu l2[100010];
bool cmp1(stu x,stu y){
	if(x.a1>y.a1){
		return true;
	}
	return false;
}
bool cmp2(stu x,stu y){
	if(x.a2>y.a2){
		return true;
	}
	return false;
}
int solve(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l1[i].a1>>l1[i].a2>>l1[i].a3;
		l2[i].a1=l1[i].a1;
		l2[i].a2=l1[i].a2;
		l2[i].a3=l1[i].a3;
		l1[i].index=i;
		l2[i].index=i;
	}
	int maxn=-1,tot;
	if (n==2){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				tot=0;
				if(i==0){
					if(j==1){
						maxn=max(maxn,l1[0].a1+l1[1].a2);
					}else if(j==2){
						maxn=max(maxn,l1[0].a1+l1[1].a3);
					}				
				}else if(i==1){
					if(j==0){
						maxn=max(maxn,l1[0].a2+l1[1].a1);
					}else if(j==2){
						maxn=max(maxn,l1[0].a2+l1[1].a3);
					}				
				}else{
					if(j==0){
						maxn=max(maxn,l1[0].a3+l1[1].a1);
					}else if(j==1){
						maxn=max(maxn,l1[0].a3+l1[1].a2);
					}				
				}
			}
		}
		return maxn;
	} 
	sort(l1,l1+n,cmp1);
	sort(l2,l2+n,cmp2);
	int ans=0;
	int cnt1=0;
	int cnt2=0;
	bool c[100001]={}; 
	for(int i=0;i<n;i++){
		if(l1[i].index==l2[i].index){
			if(l1[i].a1>l2[i].a2){
				if(cnt1<n/2){
					ans+=l1[i].a1;
					cnt1++;	
				}else{
					ans+=l2[i].a2;
					cnt2++;						
				} 
				c[l1[i].index]=true;
			}else{
				if(cnt2<n/2){
					ans+=l2[i].a2;
					cnt2++;	
				}else{
					ans+=l1[i].a1;
					cnt1++;						
				} 
				c[l2[i].index]=true;
			}
		}else{
			if(!c[l1[i].index]){
				if(cnt1<n/2){
					ans+=l1[i].a1;
					cnt1++;	
				}else{
					ans+=l2[i].a2;
					cnt2++;						
				}
				c[l1[i].index]=true;				
			}
			if(!c[l2[i].index]){
				if(cnt2<n/2){
					ans+=l2[i].a2;
					cnt2++;	
				}else{
					ans+=l1[i].a1;
					cnt1++;						
				} 	
				c[l2[i].index]=true;		
			}			
		}
	}
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	int t;
	cin>>t;
	for(int j=0;j<t;j++){
		cout<<solve()<<'\n';
	}
	return 0;
} 
