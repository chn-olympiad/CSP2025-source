#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string a,b;
struct re{
	string s1,s2;
}place[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>place[i].s1>>place[i].s2;
	}while(q--){
		cin>>a>>b;
		int l=0;
		ans=0;
		while(true){
			bool f=false;
			for(int i=0;i<l;i++){
				if(a[i]!=b[i]){
					f=true;
					break;
				}
			}if(f){
				break;
			}int r=int(a.size())-1;
			while(l<=r){
				for(int i=r+1;i<int(a.size());i++){
					if(a[i]!=b[i]){
						f=true;
						break;
					}
				}if(f){
					break;
				}string M4=a.substr(l,r-l+1),RS7=b.substr(l,r-l+1);
				for(int i=1;i<=n;i++){
					if(place[i].s1==M4&&place[i].s2==RS7){
						ans++;
						break;
					}
				}r--;
			}l++;
		}cout<<ans<<endl;
	}
	return 0;
}
