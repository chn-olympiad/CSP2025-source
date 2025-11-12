#include <bits/stdc++.h>
using namespace std;
struct g {
	int pos,val,cha;
};
int a[100010][4];
vector <g> yi,er,san;
bool cmp(g a,g b) {
	return a.cha<b.cha;
}
bool check(int n) {
	if(yi.size()>n/2||er.size()>n/2||san.size()>n/2) {
		return false;
	} else {
		return true;
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		for(int i=0; i<n; i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		yi.clear();
		er.clear();
		san.clear();
		for(int i=0; i<n; i++) {
			if(a[i][1]==max({a[i][1],a[i][2],a[i][3]})) {
				yi.push_back(g {i,a[i][1],a[i][1]-max(a[i][2],a[i][3])});
			} else if(a[i][2]==max({a[i][1],a[i][2],a[i][3]})) {
				er.push_back(g {i,a[i][2],a[i][2]-max(a[i][1],a[i][3])});
			} else if(a[i][3]==max({a[i][1],a[i][2],a[i][3]})) {
				san.push_back(g {i,a[i][3],a[i][3]-max(a[i][2],a[i][1])});
			}
		}
		sort(yi.begin(),yi.end(),cmp);
		sort(er.begin(),er.end(),cmp);
		sort(san.begin(),san.end(),cmp);
		int siz1=yi.size(),siz2=er.size(),siz3=san.size();
		int cnt1=0,cnt2=0,cnt3=0;
		while(siz1>n/2||siz2>n/2||siz3>n/2) {
			if(siz1>n/2) {
				g x=yi[cnt1];
				cnt1++;
				siz1--;
				if(a[x.pos][2]>a[x.pos][3]) {
					er.push_back(g {x.pos,a[x.pos][2],a[x.pos][2]-max(a[x.pos][1],a[x.pos][3])});
					siz2++;
				} else {
					san.push_back(g {x.pos,a[x.pos][3],a[x.pos][3]-max(a[x.pos][2],a[x.pos][1])});
					siz3++;
				}
			} else if(siz2>n/2) {
				g x=er[cnt2];
				cnt2++;
				siz2--;
				if(a[x.pos][1]>a[x.pos][3]) {
					yi.push_back(g {x.pos,a[x.pos][1],a[x.pos][1]-max(a[x.pos][2],a[x.pos][3])});
					siz1++;
				} else {
					san.push_back(g {x.pos,a[x.pos][3],a[x.pos][3]-max(a[x.pos][2],a[x.pos][1])});
					siz3++;
				}
			} else {
				g x=san[cnt3];
				cnt3++;
				siz3--;
				if(a[x.pos][1]>a[x.pos][2]) {
					yi.push_back(g {x.pos,a[x.pos][1],a[x.pos][1]-max(a[x.pos][2],a[x.pos][3])});
					siz1++;
				} else {
					er.push_back(g {x.pos,a[x.pos][2],a[x.pos][2]-max(a[x.pos][3],a[x.pos][1])});
					siz2++;
				}
			}
		}
		long long ans=0;
		for(int i=cnt1; i<yi.size(); i++) {
			ans=ans+yi[i].val;
		}
		for(int i=cnt2; i<er.size(); i++) {
			ans=ans+er[i].val;
		}
		for(int i=cnt3; i<san.size(); i++) {
			ans=ans+san[i].val;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
