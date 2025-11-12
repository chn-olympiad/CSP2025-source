#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==3){
		sort(a+1,a+4);
		if(a[3]<a[1]+a[2])
			cout<<1<<endl;
		else
			cout<<0<<endl;
		return 0;
	}
	if(n==4){
		int ans=0;
		for(int i=0;i<=1;i++)
		for(int j=0;j<=1;j++)
		for(int k=0;k<=1;k++)
		for(int s=0;s<=1;s++)
		if(i*a[1]+j*a[2]+k*a[3]+s*a[4]>2*max(i*a[1],max(j*a[2],max(k*a[3],s*a[4]))))
		ans++;
		cout<<ans<<endl;
		return 0;
	}
	if(n==5){
		int ans=0;
		for(int i=0;i<=1;i++)
		for(int j=0;j<=1;j++)
		for(int k=0;k<=1;k++)
		for(int s=0;s<=1;s++)
		for(int q=0;q<=1;q++)
		if(i*a[1]+j*a[2]+k*a[3]+s*a[4]+q*a[5]>2*max(i*a[1],max(j*a[2],max(k*a[3],max(s*a[4],q*a[5])))))
		ans++;
		cout<<ans<<endl;
		return 0;
	}
	if(n==6){
		int ans=0;
		for(int i=0;i<=1;i++)
		for(int j=0;j<=1;j++)
		for(int k=0;k<=1;k++)
		for(int s=0;s<=1;s++)
		for(int q=0;q<=1;q++)
		for(int w=0;w<=1;w++)
		if(i*a[1]+j*a[2]+k*a[3]+s*a[4]+q*a[5]+w*a[6]>2*max(i*a[1],max(j*a[2],max(k*a[3],max(s*a[4],max(q*a[5],w*a[6]))))))
		ans++;
		cout<<ans<<endl;
		return 0;
	}
	if(n==7){
		int ans=0;
		for(int i=0;i<=1;i++)
		for(int j=0;j<=1;j++)
		for(int k=0;k<=1;k++)
		for(int s=0;s<=1;s++)
		for(int q=0;q<=1;q++)
		for(int w=0;w<=1;w++)
		for(int e=0;e<=1;e++)
		if(i*a[1]+j*a[2]+k*a[3]+s*a[4]+q*a[5]+w*a[6]+e*a[7]>2*max(i*a[1],max(j*a[2],max(k*a[3],max(s*a[4],max(q*a[5],max(w*a[6],e*a[7])))))))
		ans++;
		cout<<ans<<endl;
		return 0;
	}
	if(n==8){
		int ans=0;
		for(int i=0;i<=1;i++)
		for(int j=0;j<=1;j++)
		for(int k=0;k<=1;k++)
		for(int s=0;s<=1;s++)
		for(int q=0;q<=1;q++)
		for(int w=0;w<=1;w++)
		for(int e=0;e<=1;e++)
		for(int r=0;r<=1;r++)
		if(i*a[1]+j*a[2]+k*a[3]+s*a[4]+q*a[5]+w*a[6]+e*a[7]+r*a[8]>2*max(i*a[1],max(j*a[2],max(k*a[3],max(s*a[4],max(q*a[5],max(w*a[6],max(e*a[7],r*a[8]))))))))
		ans++;
		cout<<ans<<endl;
		return 0;
	}
	if(n==9){
		int ans=0;
		for(int i=0;i<=1;i++)
		for(int j=0;j<=1;j++)
		for(int k=0;k<=1;k++)
		for(int s=0;s<=1;s++)
		for(int q=0;q<=1;q++)
		for(int w=0;w<=1;w++)
		for(int e=0;e<=1;e++)
		for(int r=0;r<=1;r++)
		for(int t=0;t<=1;t++)
		if(i*a[1]+j*a[2]+k*a[3]+s*a[4]+q*a[5]+w*a[6]+e*a[7]+r*a[8]+t*a[9]>2*max(i*a[1],max(j*a[2],max(k*a[3],max(s*a[4],max(q*a[5],max(w*a[6],max(e*a[7],max(r*a[8],t*a[9])))))))))
		ans++;
		cout<<ans<<endl;
		return 0;
	}
	if(n==10){
		int ans=0;
		for(int i=0;i<=1;i++)
		for(int j=0;j<=1;j++)
		for(int k=0;k<=1;k++)
		for(int s=0;s<=1;s++)
		for(int q=0;q<=1;q++)
		for(int w=0;w<=1;w++)
		for(int e=0;e<=1;e++)
		for(int r=0;r<=1;r++)
		for(int t=0;t<=1;t++)
		for(int y=0;y<=1;y++)
		if(i*a[1]+j*a[2]+k*a[3]+s*a[4]+q*a[5]+w*a[6]+e*a[7]+r*a[8]+t*a[9]+y*a[10]>2*max(i*a[1],max(j*a[2],max(k*a[3],max(s*a[4],max(q*a[5],max(w*a[6],max(e*a[7],max(r*a[8],max(t*a[9],y*a[10]))))))))))
		ans++;
		cout<<ans<<endl;
		return 0;
	}
}
