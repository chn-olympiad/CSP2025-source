#include<bits/stdc++.h>
using namespace std;
int t, a[114514], b[114541], c[114514], cnt1, cnt2, cnt3, ans, n;
struct p{
	int dt, h, g;
}d[114514], e[114514], f[114514];
bool cmp(p a, p b){
	if(a.g!=b.g){
		return a.g>b.g;
	}
	else return a.h>b.h;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
     cin>>t;
     while(t--){
		 cnt1=0, cnt2=0, cnt3=0, ans=0;
           cin>>n;
           for(int i=1;i<=n;i++){
			   cin>>a[i]>>b[i]>>c[i];
			   if(a[i]>b[i]&&a[i]>c[i])cnt1++;
			   if(b[i]>a[i]&&b[i]>c[i])cnt2++;
			   if(c[i]>b[i]&&c[i]>a[i])cnt3++;
		   }
		   int k=n/2, sf=0;
           if(cnt1<=k&&cnt2<=k&&cnt3<=k){
			   for(int i=1;i<=n;i++){
				   ans+=max(a[i], max(b[i], c[i]));
			   }
		   }
		   else if(cnt1>k){
			   for(int i=1;i<=n;i++){
				   if(a[i]>b[i]&&a[i]>c[i]){
				
					   sf++;
					   d[sf].dt=i, d[sf].h=a[i], d[sf].g=a[i]-max(b[i], c[i]);
					   a[i]=-1;
				   }
			   }
			    sort(d+1, d+1+sf, cmp);
			   for(int i=1;i<=k;i++){
				   ans+=d[i].h;
				   a[d[i].dt]=-2;
			   }
			   
			   for(int i=1;i<=n;i++){
				   if(a[i]==-2)continue;
				   ans+=max(a[i], max(b[i], c[i]));
			   }
		   }
		   else if(cnt2>k){
			   for(int i=1;i<=n;i++){
				   if(b[i]>a[i]&&b[i]>c[i]){
					   
					   sf++;
					   d[sf].dt=i, d[sf].h=b[i], d[sf].g=b[i]-max(a[i], c[i]);
					   b[i]=-1;
				   }
			   }
			    sort(d+1, d+1+sf, cmp);
			   for(int i=1;i<=k;i++){
				   ans+=d[i].h;
				   b[d[i].dt]=-2;
			   }
			   for(int i=1;i<=n;i++){
				   if(b[i]==-2)continue;
				   ans+=max(a[i], max(b[i], c[i]));
			   }
		   }
		   else if(cnt3>k){
			   for(int i=1;i<=n;i++){
				   if(c[i]>b[i]&&c[i]>a[i]){
					   
					   sf++;
					   d[sf].dt=i, d[sf].h=c[i], d[sf].g=c[i]-max(b[i], a[i]);
					   c[i]=-1;
				   }
			   }
			    sort(d+1, d+1+sf, cmp);
			   for(int i=1;i<=k;i++){
				   ans+=d[i].h;
				   c[d[i].dt]=-2;
			   }
			   for(int i=1;i<=n;i++){
				   if(c[i]==-2)continue;
				   ans+=max(a[i], max(b[i], c[i]));
			   }
		   }
           cout<<ans<<endl;
           
     }
     
     return 0;
}
