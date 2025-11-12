#include<bits/stdc++.h>
using namespace std;
long long n,t,s1,s2,s3;
struct node1{
	long long s[4];
	int f,se;
}a[110000];
struct node2{
	long long s,xb,cha;
}a1[110000],a2[110000],a3[110000];
bool cmp(node2 l,node2 r){
	return l.cha<r.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		n=0;
		long long ans=0;
		s1=0,s2=0,s3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].s[1]>>a[i].s[2]>>a[i].s[3];
			long long maxx=max(a[i].s[1],max(a[i].s[2],a[i].s[3]));
			ans+=maxx;
			if(maxx==a[i].s[1]){
				s1++;
				if(a[i].s[2]>=a[i].s[3]){
					a1[s1].cha=a[i].s[1]-a[i].s[2];
				}else{
					a1[s1].cha=a[i].s[1]-a[i].s[3];
				}
			}else
			if(maxx==a[i].s[2]){
				s2++;	
				if(a[i].s[1]>=a[i].s[3]){
					a2[s2].cha=a[i].s[2]-a[i].s[1];
				}else{
					a2[s2].cha=a[i].s[2]-a[i].s[3];
				}
			}else
			if(maxx==a[i].s[3]){
				s3++;		
				if(a[i].s[2]>=a[i].s[1]){
					a3[s3].cha=a[i].s[3]-a[i].s[2];
				}else{
					a3[s3].cha=a[i].s[3]-a[i].s[1];
				}
			}						
			
		}
		if(s1<=n/2&&s2<=n/2&&s3<=n/2){
			cout<<ans<<endl;
			continue;  
		}else{
			if(s1>n/2){
				sort(a1+1,a1+s1+1,cmp);	
				s1-=n/2;
				for(int i=1;i<=s1;i++){
					ans-=a1[i].cha;
				}
				cout<<ans<<endl;
			}else if(s2>n/2){
				sort(a2+1,a2+s2+1,cmp);	
				s2-=n/2;
				for(int i=1;i<=s2;i++){
					ans-=a2[i].cha;
				}
				cout<<ans<<endl;				
			}else{
				sort(a3+1,a3+s3+1,cmp);	
				s3-=n/2;
				for(int i=1;i<=s3;i++){
					ans-=a3[i].cha;
				}
				cout<<ans<<endl;				
			}
			
			
			
		}
	
	
	
		
	}
	
	
	return 0;
} 
