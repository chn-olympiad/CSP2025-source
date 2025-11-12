#include<bits/stdc++.h>
using namespace std;
struct node{
	int minus=0,bian=0;
};
int cmp(node a,node b){
	return a.minus<b.minus;
}
int main(){
    cin.tie(0);cout.tie(0);
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int a[n+5],b[n+5],c[n+5],maxa=-100,maxb=-100,maxc=-100,ans=0;
		for(int i=1;i<=n;i++)
		  cin>>a[i]>>b[i]>>c[i],maxa=max(maxa,a[i]),maxb=max(maxb,b[i]),maxc=max(maxc,c[i]);
		if(maxb==0&&maxc==0){
			sort(a+1,a+n+1);
			for(int i=n;i>=n/2+1;i--)
			  ans+=a[i];
			cout<<ans<<endl;
			continue;
		}
		if(maxc==0){
			node minu[n+5];
			for(int i=1;i<=n;i++)
			  ans+=a[i],minu[i].minus=a[i]-b[i];
			sort(minu+1,minu+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			  ans-=minu[i].minus;
			cout<<ans<<endl;
			continue;
		}
		if(n==2)
		  cout<<max(a[1]+b[2],max(a[1]+c[2],max(b[1]+a[2],max(b[1]+c[2],max(c[1]+a[2],c[1]+b[2])))));
		if(n==4){
			int num[20]={};
			int num[1]=a[1]+a[2]+b[3]+b[4],num[2]=a[1]+a[2]+b[3]+c[4],num[3]=a[1]+a[2]+c[3]+b[4],num[4]=a[1]+a[2]+c[3]+c[4];
			int num[5]=a[1]+a[3]+b[2]+b[4],num[6]=a[1]+a[3]+b[2]+c[4],num[7]=a[1]+a[3]+c[2]+b[4],num[8]=a[1]+a[3]+c[2]+c[4];
			int num[9]=a[1]+a[4]+b[2]+b[3],num[10]=a[1]+a[4]+b[2]+c[2],num[11]=a[1]+a[4]+c[2]+b[3],num[12]=a[1]+a[4]+c[2]+c[3];
			sort(a+1,a+13);
			cout<<num[12];
		} 
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
