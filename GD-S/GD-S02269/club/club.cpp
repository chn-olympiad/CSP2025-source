#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100005];
int b[100005];
int c[100005];
vector<int> h;
int func(){
	int ca=0,cb=0,cc=0;
	for(int i=1;i<=n;i++){
		if(a[i]>=b[i] && a[i]>=c[i]){
			ca++;
		}else if(b[i]>=a[i] && b[i]>=c[i]){
			cb++;
		}else{
			cc++;
		}
	}
	int ans=0;
	if(ca<=n/2 && cb<=n/2 && cc<=n/2){
		for(int i=1;i<=n;i++){
			ans+=max(max(a[i],b[i]),c[i]);
		}
	}else{
		if(ca>n/2){
			for(int i=1;i<=n;i++){
				if(a[i]>=b[i] && a[i]>=c[i]){
					ans+=a[i];
					h.push_back(min(a[i]-b[i],a[i]-c[i]));
				}else{
					ans+=max(b[i],c[i]);
				}
			} 
			sort(h.begin(),h.end());
			for(int i=0;i<ca-n/2;i++){
				ans-=h[i];
			}
		}else if(cb>n/2){
			for(int i=1;i<=n;i++){
				if(b[i]>=a[i] && b[i]>=c[i]){
					ans+=b[i];
					h.push_back(min(b[i]-a[i],b[i]-c[i]));
				}else{
					ans+=max(a[i],c[i]);
			    }
			} 
			sort(h.begin(),h.end());
			for(int i=0;i<cb-n/2;i++){
				ans-=h[i];
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(c[i]>=a[i] && c[i]>=b[i]){
					ans+=c[i];
					h.push_back(min(c[i]-a[i],c[i]-b[i]));
				}else{
					ans+=max(a[i],b[i]);
				}
			}
			sort(h.begin(),h.end());
			for(int i=0;i<cc-n/2;i++){
				ans-=h[i];
			}
		}
	}
	h.clear();
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		cout<<func()<<endl;
	}
	return 0;
}
