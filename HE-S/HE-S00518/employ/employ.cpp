#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,c[502],ans,e[502];
bool h[502];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1') h[i+1]=1;
		else h[i+1]=0;
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	sort(c+1,c+1+n);
	int ls=0;
	for(int i=1;i<=n;i++)e[i]=c[i];
	for(int i=1;i<=n;i++){
		if(e[i]<=0) continue;
		else if(!h[i]){
			for(int j=i+1;j<=n;j++) e[j]-=2;
		}
		else if(h[i]){
			ls++;
			for(int j=i+1;j<=n;j++) e[j]--;
		}
	}
	if(ls>=m) ans++;
	for(int f=1;f<=n;f++){
		for(int l=1;l<=n;l++){
			swap(c[l],c[l+1]);
			for(int i=1;i<=n;i++) e[i]=c[i];
			ls=0;
			for(int i=1;i<=n;i++){
				if(e[i]<=0) continue;
				 else if(!h[i]){
					for(int j=i+1;j<=n;j++) e[j]-=2;
				}
				else if(h[i]){
					ls++;
					for(int j=i+1;j<=n;j++) e[j]--;
				}
			}
		if(ls>=m) ans++;
		}
	}
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
