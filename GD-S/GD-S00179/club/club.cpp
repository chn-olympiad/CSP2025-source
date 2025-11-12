#include<bits/stdc++.h>
using namespace std;
#define int long long
int t;
int n;
struct info{
	int a,b,c;
}x[100005];
int aa[100005],bb[100005],cc[100005];
int asi,bsi,csi;
bool cmpa(const int &xx,const int &yy){
	return (x[xx].a-((x[xx].b>x[xx].c)?x[xx].b:x[xx].c))>(x[yy].a-((x[yy].b>x[yy].c)?x[yy].b:x[yy].c));
}
bool cmpb(const int &xx,const int &yy){
	return (x[xx].b-((x[xx].a>x[xx].c)?x[xx].a:x[xx].c))>(x[yy].b-((x[yy].a>x[yy].c)?x[yy].a:x[yy].c));
}
bool cmpc(const int &xx,const int &yy){
	return (x[xx].c-((x[xx].a>x[xx].b)?x[xx].a:x[xx].b))>(x[yy].c-((x[yy].a>x[yy].b)?x[yy].a:x[yy].b));
}
void solve(){
	asi=0;
	bsi=0;
	csi=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i].a>>x[i].b>>x[i].c;
		if(x[i].a>=x[i].b&&x[i].a>=x[i].c){
			aa[++asi]=i;
		}else if(x[i].b>=x[i].a&&x[i].b>=x[i].c){
			bb[++bsi]=i;
		}else{
			cc[++csi]=i;
		}
	}
	if(asi>n/2){
		sort(aa+1,aa+asi+1,cmpa);
		while(asi>n/2){
			int now=aa[asi];
			asi--;
			if(x[now].b>x[now].c){
				bb[++bsi]=now;
			}else{
				cc[++csi]=now;
			}
		}
	}else if(bsi>n/2){
		sort(bb+1,bb+bsi+1,cmpb);
		while(bsi>n/2){
			int now=bb[bsi];
			bsi--;
			if(x[now].a>x[now].c){
				aa[++asi]=now;
			}else{
				cc[++csi]=now;
			}
		}
	}else if(csi>n/2){
		sort(cc+1,cc+csi+1,cmpc);
		while(csi>n/2){
			int now=cc[csi];
			csi--;
			if(x[now].b>x[now].a){
				bb[++bsi]=now;
			}else{
				aa[++asi]=now;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=asi;i++){
		ans+=x[aa[i]].a;
	}
	for(int i=1;i<=bsi;i++){
		ans+=x[bb[i]].b;
	}
	for(int i=1;i<=csi;i++){
		ans+=x[cc[i]].c;
	}
	cout<<ans<<'\n';
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
