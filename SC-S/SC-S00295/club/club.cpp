#include<bits/stdc++.h>
using namespace std;
int T,n,s,mn;
int a1[100010],a2[100010],a3[100010];
int vis[100010],vis1[100010],vis2[100010],vis3[100010];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		s=0;
		for(int i=1;i<=n;i++){vis[i]=0;vis1[i]=0;vis2[i]=0;vis3[i]=0;}
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a1[i]==0) vis1[i]=1;
			if(a2[i]==0) vis2[i]=1;
			if(a3[i]==0) vis3[i]=1;
			if(a1[i]==a2[i] && a1[i]==a3[i]){s+=a1[i];vis[i]=1;}
			else if(a1[i]>a2[i] && a1[i]>a3[i]) vis1[i]=2;
			else if(a2[i]>a3[i] && a2[i]>a1[i]) vis2[i]=2;
			else if(a3[i]>a2[i] && a3[i]>a1[i]) vis3[i]=2;
		}
		for(int i=1;i<=n;i++){
			if(vis[i]!=1 && vis1[i]==2)
				s+=a1[i];
			else if(vis[i]!=1 && vis2[i]==2)
				s+=a2[i];
			else if(vis[i]!=1 && vis3[i]==2)
				s+=a3[i];
		}
		cout<<s<<"\n";
	}
	
	return 0;
}