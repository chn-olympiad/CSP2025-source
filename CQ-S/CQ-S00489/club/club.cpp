#include<bits/stdc++.h>
using namespace std;
struct nn{
	int a,b,c;
	friend bool operator <(nn a,nn b){
		return a.a+b.b>a.b+b.a;
	}
}a[100001];
bool cmp(nn a,nn b){
	return a.a>b.a;
}
int n;
int ans;
void az(int i,int num,int aji,int bji,int cji){
	if(i==n+1){
		if(ans<num) ans=num;
		return ;
	}
	if(aji<n/2)az(i+1,num+a[i].a,aji+1,bji,cji);
	if(bji<n/2)az(i+1,num+a[i].b,aji,bji+1,cji);
	if(cji<n/2)az(i+1,num+a[i].c,aji,bji,cji+1);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		bool dA=1,dB=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b!=0) dA=0;
			if(a[i].c!=0) dB=0;
		}
		if(n<=10){
			az(1,0,0,0,0);
			cout<<ans<<'\n';
			continue;
		}
		if(dA){
			sort(a+1,a+n+1,cmp);
			int ans=0;
			for(int i=1;i<=n/2;i++)
				ans+=a[i].a;
			cout<<ans;
			continue;
		}
		int aji=0,bji=0,cji=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i].a>a[i].b&&a[i].a>a[i].c){
				if(aji<n/2){
					aji++;
					ans+=a[i].a;
				}
				else{
					if(a[i].b>a[i].c){
						bji++;
						ans+=a[i].b;
					}
					else{
						cji++;
						ans+=a[i].c;
					}
				}
			}
			if(a[i].b>a[i].a&&a[i].b>a[i].c){
				if(bji<n/2){
					bji++;
					ans+=a[i].b;
				}
				else{
					if(a[i].a>a[i].c){
						aji++;
						ans+=a[i].a;
					}
					else{
						cji++;
						ans+=a[i].c;
					}
				}
			}
			if(a[i].c>a[i].b&&a[i].c>a[i].a){
				if(cji<n/2){
					cji++;
					ans+=a[i].c;
				}
				else{
					if(a[i].a>a[i].b){
						aji++;
						ans+=a[i].a;
					}
					else {
						bji++;
						ans+=a[i].c;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
}
