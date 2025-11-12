#include<bits/stdc++.h>
using namespace std; 
const int N=1e5+5;
int n,T;
long long ans;
int a1[N],a2[N],a3[N],maxx[N],minn[N],a[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n==2){
			for(int i=1;i<=n;i++){
				cin>>a1[i]>>a2[i];
				maxx[i]=max(a1[i],a2[i]);
				minn[i]=min(a1[i],a2[i]);
				cin>>a3[i];
				maxx[i]=max(a3[i],maxx[i]);
				minn[i]=min(a3[i],minn[i]);
				a[i]=a1[i]+a2[i]+a3[i]-maxx[i]-minn[i];
			} 
			if((maxx[1]==a1[1]&&maxx[2]!=a1[2])||(maxx[1]!=a1[1]&&maxx[2]==a1[2])) ans=maxx[1]+maxx[2];
			if((maxx[1]==a2[1]&&maxx[2]!=a2[2])||(maxx[1]!=a2[1]&&maxx[2]==a2[2])) ans=maxx[1]+maxx[2];
			if((maxx[1]==a3[1]&&maxx[2]!=a3[2])||(maxx[1]!=a3[1]&&maxx[2]==a3[2])) ans=maxx[1]+maxx[2];
			if((maxx[1]==a1[1]&&maxx[2]==a1[2])||(maxx[1]==a2[1]&&maxx[2]==a2[2])||(maxx[1]==a3[1]&&maxx[2]==a3[2])){
				if(maxx[1]>maxx[2]) ans=maxx[1]+a[2];
				if(maxx[1]=maxx[2]) ans=maxx[1]+max(a[1],a[2]);
				if(maxx[1]<maxx[2]) ans=maxx[2]+a[1];
			}
		}
		else{
			for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i];
			maxx[i]=a1[i]>=a2[i]?a1[i]:a2[i];
			cin>>a3[i];
			maxx[i]=a3[i]>=maxx[i]?a3[i]:maxx[i];
		}
		sort(maxx+1,maxx+1+n);
		for(int i=n/2+1;i<=n;i++){
			ans+=maxx[i];
		}
		
	}
	cout<<ans;
		ans=0;
		}	
	return 0;
}