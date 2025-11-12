#include<bits/stdc++.h> 
using namespace std;
const int mn=100005;
int t,n,mx,sum;
int x1,x2,x3;
int a1[mn],a2[mn],a3[mn];
int xz[mn],c1[mn],c2[mn],c3[mn];
int main(){ 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		sum=0,x1=0,x2=0,x3=0;
		cin>>n;
		int d=n/2;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			mx=max(max(a1[i],a2[i]),a3[i]);
			if(a1[i]==mx){
				xz[i]=1;
				x1++;
				c1[x1]=min(a1[i]-a2[i],a1[i]-a3[i]);
			}if(a2[i]==mx){
				xz[i]=2;
				x2++;
				c2[x2]=min(a2[i]-a1[i],a2[i]-a3[i]);
			}if(a3[i]==mx){
				xz[i]=3;
				x3++;
				c3[x3]=min(a3[i]-a2[i],a3[i]-a1[i]);
			}
			sum+=mx;
		}
		if(x1>d){
			sort(c1+1,c1+x1+1);
			for(int i=1;i<=x1-d;i++){
				sum-=c1[i];
			}
		}if(x2>d){
			sort(c2+1,c2+x2+1);
			for(int i=1;i<=x2-d;i++){
				sum-=c2[i];
			}
		}if(x3>d){
			sort(c3+1,c3+x3+1);
			for(int i=1;i<=x3-d;i++){
				sum-=c3[i];
			}
		}cout<<sum<<endl;
		
	}
	return 0;
}
