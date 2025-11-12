#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	string x,y;
}arr[200005];
int n,q; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL),cout.tie(NULL); 
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>arr[i].x>>arr[i].y;
		if(arr[i].x==arr[i].y) i--,n--;
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size()) cout<<"0\n";
		else{
			bool flag=1;
			int cnt=0;
			string x="",y="";
			for(int i=0;i<a.size();i++){
				if(a[i]!=b[i]){
					x+=a[i],y+=b[i];
					if(flag) cnt++,flag=0;
				}else{
					flag=1;
				}
			}
			if(cnt!=1) cout<<"0\n";
			else{
				int ans=0;
				for(int i=1;i<=n;i++){
					if(a.size()<arr[i].x.size()) continue;
					if(x.size()>arr[i].x.size()) continue;
					if(a.find(arr[i].x)<a.size()&&b.find(arr[i].y)<b.size()&&arr[i].x.find(x)<arr[i].x.size()&&arr[i].y.find(y)<arr[i].y.size()){
						ans++;
					}
				}
				cout<<ans<<'\n';
			}
		}
	}
	return 0;
}

