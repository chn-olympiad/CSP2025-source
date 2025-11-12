#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int x, y, z;
};
int n, ans;
vector<int> vc;
vector<node> a, b, c;
bool cmp(node x, node y){
	return x.x<y.x;
}
bool cmb(node x, node y){
	return x.y<y.y;
}
bool cmc(node x, node y){
	return x.z<y.z;
}
void worka(){
	sort(a.begin(), a.end(), cmp);
	for(int i=0;i<a.size()-(n/2);i++){
		if(a[i].y>a[i].z&&b.size()<(n/2)){
			b.push_back({a[i].x, a[i].y, a[i].z});
		}else{
			c.push_back({a[i].x, a[i].y, a[i].z});
		}
	}
	for(int i=a.size()-(n/2);i<a.size();i++){
		ans+=a[i].x;
	}
	for(int i=0;i<b.size();i++){
		ans+=b[i].y;
	}
	for(int i=0;i<c.size();i++){
		ans+=c[i].z;
	}
} 
void workb(){
	sort(b.begin(), b.end(), cmb);
	for(int i=0;i<b.size()-(n/2);i++){
		if(b[i].y>b[i].z&&a.size()<(n/2)){
			a.push_back({b[i].x, b[i].y, b[i].z});
		}else{
			c.push_back({b[i].x, b[i].y, b[i].z});
		}
	}
	for(int i=b.size()-(n/2);i<b.size();i++){
		ans+=b[i].y;
	}
	for(int i=0;i<a.size();i++){
		ans+=a[i].x;
	}
	for(int i=0;i<c.size();i++){
		ans+=c[i].z;
	}
}
void workc(){
	sort(c.begin(), c.end(), cmc);
	for(int i=0;i<c.size()-(n/2);i++){
		if(c[i].y>c[i].z&&b.size()<(n/2)){
			b.push_back({c[i].x, c[i].y, c[i].z});
		}else{
			a.push_back({c[i].x, c[i].y, c[i].z});
		}
	}
	for(int i=c.size()-(n/2);i<c.size();i++){
		ans+=c[i].z;
	}
	for(int i=0;i<b.size();i++){
		ans+=b[i].y;
	}
	for(int i=0;i<a.size();i++){
		ans+=c[i].x;
	}
}
int t;
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		ans=0;
		a.clear();
		b.clear();
		c.clear();
		cin >> n;
		int fb=1, fc=1;
		for(int i=1;i<=n;i++){
			int xx, yy, zz;
			cin >> xx >> yy >> zz;
			vc.push_back(xx);
			if(yy!=0)fb=0;
			if(zz!=0)fc=0;
			if(xx>=yy&&xx>=zz){
				a.push_back({xx, yy, zz});
			}else if(yy>=xx&&yy>=zz){
				b.push_back({xx, yy, zz});
			}else{
				c.push_back({xx, yy, zz});
			}
		}
		if(fb==1&&fc==1){
			sort(vc.begin(), vc.end());
			for(int i=vc.size()-1;i>=vc.size()-(n/2);i--){
				ans+=vc[i];
			}
			cout << ans << endl;
			continue;
		}
		if(a.size()<=n/2&&b.size()<=n/2&&c.size()<=n/2){
			for(int i=0;i<a.size();i++)ans+=a[i].x;
			for(int i=0;i<b.size();i++)ans+=b[i].y;
			for(int i=0;i<c.size();i++)ans+=c[i].z;
			cout << ans << endl;
			continue;
		}
		if(a.size()>n/2){
			worka();
		}
		if(b.size()>n/2){
			workb();
		}
		if(c.size()>n/2){
			workc();
		}
		cout << ans << endl;
	}
	return 0;
} 
