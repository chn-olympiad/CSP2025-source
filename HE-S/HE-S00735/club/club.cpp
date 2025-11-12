#include <bits/stdc++.h>
using namespace std;
int T,n,ans,A,B,C,tmax;
int a[100005],b[100005],c[100005],ansa,ansb,ansc;
pair<int ,int> dd[100005];

void afind(int x,int maxn){
	for (int i=0;i<maxn;i++){
		for (int j=0;j<n;j++){
			if (dd[j].first==x){
				if (dd[j].second>tmax){
					tmax=dd[j].second;
					dd[j].second=0;
					dd[j].first=0;
				}		
			}
		}
		ans+=tmax;
		tmax=0;
	}
	for (int i=0;i<n;i++){
		if (dd[i].first==x){
			dd[i].first++;
			if (x==1)dd[i].second=b[i];
			if (x==2)dd[i].second=c[i];
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while (T--){
		cin >> n;
		int maxn=n/2;
		for (int i=0;i<n;i++){
			cin >> a[i] >> b[i] >> c[i];
			if(a[i]>b[i]&&a[i]>c[i]){
				dd[i].first=1;
				A++;
				dd[i].second=a[i];
				ansa+=a[i];
			}else if (b[i]>a[i]&&b[i]>c[i]){
				dd[i].first=2;
				B++;
				dd[i].second=b[i];
				ansb+=b[i];
			}else if (c[i]>a[i]&&c[i]>b[i]){
				dd[i].first=3;
				C++;
				dd[i].second=c[i];
				ansc+=c[i];
			}
		}
		if (A>maxn){
			afind(1,maxn);
		}else{
			ans+=ansa;
		}
		if (B>maxn){
			afind(2,maxn); 
		}else{
			ans+=ansb;
		}
		if (C>maxn){
			afind(3,maxn);
		}else{
			ans+=ansc;
		}	 
		cout << ans << endl;
	}
	
return 0;	
}
