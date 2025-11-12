#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z,m,k;
}a[500005];
bool cmp(node x,node y){
	return x.k<y.k;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,cnt=0,cnta=0,cntb=0,cntc=0;
	long long ans=0;
	cin>>t;
	while(t--){
	    cin>>n;
	    for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		    a[i].k=2*(max(max(a[i].x,a[i].y),a[i].z))+min(min(a[i].x,a[i].y),a[i].z)-a[i].x-a[i].y-a[i].z;
			if(a[i].x==max(max(a[i].x,a[i].y),a[i].z)){
				a[i].m=1;
				cnta++;
				ans+=a[i].x;
			}
			if(a[i].y==max(max(a[i].x,a[i].y),a[i].z)){
				a[i].m=2;
				cntb++;
				ans+=a[i].y;
			}
			if(a[i].z==max(max(a[i].x,a[i].y),a[i].z)){
				a[i].m=3;
				cntc++;
				ans+=a[i].z;
			}
		}
		if(cnta>n/2){
			sort(a+1,a+1+n,cmp);
			for(int j=1;j<=n;){
					if(a[j].m==1) ans-=a[j].k;
					cnt++;
					if(cnt==cnta-n/2) break;
			}
		}
		else if(cntb>n/2){
			sort(a+1,a+1+n,cmp);
			for(int j=1;j<=n;){
					if(a[j].m==2) ans-=a[j].k;
					cnt++;
					if(cnt==cntb-n/2) break;
			}
		}
		else if(cntc>n/2){
			sort(a+1,a+1+n,cmp);
			for(int j=1;j<=n;){
					if(a[j].m==3) ans-=a[j].k;
					cnt++;
					if(cnt==cntc-n/2) break;
			}
		}
		cout<<ans<<endl;
		ans=0,cnt=0,cnta=0,cntb=0,cntc=0;
	}	
	fclose(stdin);
	fclose(stdout);
    return 0;
}
