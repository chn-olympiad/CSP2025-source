#include<bits/stdc++.h>
using namespace std;
struct club {
	int id,hml;
} first[100010],scend[100010],third[100010];
struct club1 {
	int id,wbm;
} maxx[100010];
int t,n,use[100010];
bool cmp(club x,club y) {
	return x.hml>y.hml;
}
//int find(club a[],int n,int mb) {
//	for(int i=1; i<=n; i++) {
//		if(a[i].id==mb) {
//			return i;
//		}
//	}
//	return -1;
//}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		int ans=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>first[i].hml>>scend[i].hml>>third[i].hml;
//			first[i].id=scend[i].id=third[i].id=maxx[i].id=i;
//			if(first[i].hml>scend[i].hml) {
//				if(first[i].hml>third[i].hml) {
//					maxx[i].wbm=1;
//				} else {
//					maxx[i].wbm=3;
//				}
//			} else if(scend[i].hml>third[i].hml) {
//				if(scend[i].hml>first[i].hml) {
//					maxx[i].wbm=2;
//				} else {
//					maxx[i].wbm=1;
//				}
//			} else if(third[i].hml>first[i].hml) {
//				if(third[i].hml>scend[i].hml) {
//					maxx[i].wbm=3;
//				} else {
//					maxx[i].wbm=2;
//				}
//			}
		}
		sort(first+1,first+1+n,cmp);
//		sort(scend+1,scend+1+n,cmp);
//		sort(third+1,third+1+n,cmp);
		for(int i=1; i<=n/2; i++) {
			ans+=first[i].hml;
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
