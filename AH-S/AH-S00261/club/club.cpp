#include<bits/stdc++.h>
using namespace std;
long long n,ans=0,a[100005],b[100005],c[100005];
void px(int i,int sum,int x,int y,int z){
	i++;
	if(i>n){
		if(ans<sum && x<=n/2 && y<=n/2 && z<=n/2){
			ans=sum;
		}
		return;
	}
	if(a[i]== b[i]|| a[i]==c[i] || c[i]==b[i]){
		if(x<n/2){px(i,sum+a[i],x++,y,z);}
		if(y<n/2){px(i,sum+b[i],x,y++,z);}
		if(z<n/2){px(i,sum+c[i],x,y,z++);}
	}
	else{
		if(a[i]<b[i] && a[i]<c[i]){
			if(y<n/2){px(i,sum+b[i],x,y++,z);}
			if(z<n/2){px(i,sum+c[i],x,y,z++);}
		}
		if(b[i]<a[i] && b[i]<c[i]){
			if(x<n/2){px(i,sum+a[i],x++,y,z);}
			if(z<n/2){px(i,sum+c[i],x,y,z++);}
		}
		if(c[i]<a[i] && c[i]<b[i]){
			if(x<n/2){px(i,sum+a[i],x++,y,z);}
			if(y<n/2){px(i,sum+b[i],x,y++,z);}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
		long long z=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0 || c[i]!=0){
				z=1;
			}
		}
		if(n==2){
			int q,w,e;
			q=max(b[1]+a[2],c[1]+a[2]);
			w=max(a[1]+b[2],c[1]+b[2]);
			e=max(a[1]+c[2],b[1]+c[2]);
			cout<<max(q,max(w,e));
		}
		else if(z==0){
			sort(a+1,a+n+1);
			for(int i=n/2+1;i<=n;i++){
				ans+=a[i];
			}
			cout<<ans<<endl;
			ans=0;
		}
		else{
			px(0,0,0,0,0);
			cout<<ans<<endl;
			ans=0;
		}
	}
}
