#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],n,t;
bool ch(int sa,int sb,int sc){
	if(sa<=n/2&&sb<=n/2&&sc<=n/2) return 1;
	else return 0;
}
vector<int> sh;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0;
		int sa=0,sb=0,sc=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]) sa++,ans+=a[i];
			else if(b[i]>=a[i]&&b[i]>=c[i]) sb++,ans+=b[i];
			else if(c[i]>=b[i]&&c[i]>=a[i]) sc++,ans+=c[i];
		}
		if(!ch(sa,sb,sc)){
			if(sa>n/2){
				for(int i=1;i<=n;i++){
					if(max(a[i],max(b[i],c[i]))==a[i]){
						if(max(b[i],c[i])==b[i]){
							sh.push_back(a[i]-max(b[i],c[i]));
						}else{
							sh.push_back(a[i]-max(b[i],c[i]));
						}
					}
				}
			}
			if(sb>n/2){
				for(int i=1;i<=n;i++){
					if(max(a[i],max(b[i],c[i]))==b[i]){
						if(max(a[i],c[i])==a[i]){
							sh.push_back(b[i]-max(a[i],c[i]));
						}else{
							sh.push_back(b[i]-max(a[i],c[i]));
						}
					}
				}
			}
			if(sc>n/2){
				for(int i=1;i<=n;i++){
					if(max(a[i],max(b[i],c[i]))==c[i]){
						if(max(a[i],b[i])==a[i]){
							sh.push_back(c[i]-max(a[i],b[i]));
						}else{
							sh.push_back(c[i]-max(a[i],b[i]));
						}
					}
				}
			}
			sort(sh.begin(),sh.end(),cmp);
			for(int i=0;i<max(sa,max(sb,sc))-n/2;i++){
				ans-=sh[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
