#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e5+5;
struct Node{
     int x,y,z,m1,m2;
}a[N];
int ans[N];
int l[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
        for(int i=1;i<=n;i++){
            int ai=a[i].x,bi=a[i].y,ci=a[i].z;
            if(ai<bi) swap(ai,bi); 
            if(bi<ci) swap(bi,ci);
            if(ai<bi) swap(ai,bi); 
            if(bi<ci) swap(bi,ci);
            if(ai<bi) swap(ai,bi); 
            if(bi<ci) swap(bi,ci);
            a[i].m1=ai; a[i].m2=bi;
        }
        long long cnt=0;
        for(int i=1;i<=n;i++) cnt+=a[i].m1;
        for(int i=1;i<=n;i++){
			if(a[i].x==max(max(a[i].x,a[i].y),a[i].z)) ans[1]++;
			else{
				if(a[i].y==max(max(a[i].x,a[i].y),a[i].z)) ans[2]++;
				else{
					if(a[i].z==max(max(a[i].x,a[i].y),a[i].z)) ans[3]++;
				}
			}
		}
		int k=max(max(ans[1],ans[2]),ans[3]);
		if(k<=n/2){
			cout<<cnt<<endl;
		}
		else{
		    if(ans[1]==k){
                 int nn=0;
                 for(int i=1;i<=n;i++){
					 if(a[i].x==a[i].m1){
						 l[++nn]=a[i].x-a[i].m2;
					 }
				 }
				 sort(l+1,l+nn+1);
				 for(int i=1;i<=k-n/2;i++) cnt-=l[i];
				 cout<<cnt<<endl;
            }
            if(ans[2]==k){
				 int nn=0;
                 for(int i=1;i<=n;i++){
					 if(a[i].y==a[i].m1){
						 l[++nn]=a[i].y-a[i].m2;
					 }
				 }
				 sort(l+1,l+nn+1);
				 for(int i=1;i<=k-n/2;i++) cnt-=l[i];
				 cout<<cnt<<endl;
			}
			if(ans[3]==k){
				 int nn=0;
                 for(int i=1;i<=n;i++){
					 if(a[i].z==a[i].m1){
						 l[++nn]=a[i].z-a[i].m2;
					 }
				 }
				 sort(l+1,l+nn+1);
				 for(int i=1;i<=k-n/2;i++) cnt-=l[i];
				 cout<<cnt<<endl;
			}
		}
        memset(a,0,sizeof(a));
        memset(ans,0,sizeof(ans));
        memset(l,0,sizeof(l));
    }
    return 0;
}
