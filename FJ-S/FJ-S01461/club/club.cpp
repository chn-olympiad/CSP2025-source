#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,n,b=0;
	cin>>t;
	for(long long q=0;q<t;q++){
		long long bluba=0,blubb=0,blubc=0,ans=0;
		cin>>n;
		long long d[n+10][4]={};
		long long a[n+10][5];
		b=n/2;
		for(long long i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(long long i=1;i<=n;i++){
			long long j=max(max(a[i][1],a[i][2]),a[i][3]);
			d[i][1]=j-a[i][1];
			d[i][2]=j-a[i][2];
			d[i][3]=j-a[i][3];
			if(d[i][1]>=d[i][2]) swap(d[i][1],d[i][2]);
			if(d[i][2]>=d[i][3]) swap(d[i][2],d[i][3]);
			if(d[i][1]>=d[i][2]) swap(d[i][1],d[i][2]);
			if(max(max(a[i][1],a[i][2]),a[i][3])==a[i][1]) bluba++;
			if(max(max(a[i][1],a[i][2]),a[i][3])==a[i][2]) blubb++;
			if(max(max(a[i][1],a[i][2]),a[i][3])==a[i][3]) blubc++;
		}
		for(long long i=1;i<=n;i++){
			ans+=max(max(a[i][1],a[i][2]),a[i][3]);
		}
		if(bluba<=b&&blubb<=b&&blubc<=b){
			cout<<ans<<endl;
		}
		else if(bluba>b){
			long long d1=bluba-b;
			long long e[bluba+10]={},e1=0;
			for(long long i=1;i<=n;i++){
				if(max(max(a[i][1],a[i][2]),a[i][3])==a[i][1]){
				e1++;	
				e[e1]=d[i][2];	
				}
			}
			sort(e,e+e1);
			for(long long i=1;i<=d1;i++){
				ans=ans-e[i];
			}
			cout<<ans<<endl;
		}
		else if(blubb>b){
			long long d1=blubb-b;
			long long e[blubb+10]={},e1=0;
			for(long long i=1;i<=n;i++){
				if(max(max(a[i][1],a[i][2]),a[i][3])==a[i][2]){
					e1++;
					e[e1]=d[i][2];
				}
			}
			sort(e,e+e1+1);
			for(long long i=1;i<=d1;i++){
				ans=ans-e[i];
			}
			cout<<ans<<endl;
		}
		else if(blubc>b){
			long long d1=blubc-b;
			long long e[blubc+10]={},e1=0;
			for(long long i=1;i<=n;i++){
				if(max(max(a[i][1],a[i][2]),a[i][3])==a[i][3]){
					e1++;
					e[e1]=d[i][2];
				}
			}
			sort(e,e+e1+1);
			for(long long i=1;i<=d1;i++){
				ans=ans-e[i];
			}
			cout<<ans<<endl;
		}
	}
}
