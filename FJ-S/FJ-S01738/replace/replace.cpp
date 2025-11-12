#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct node{
	string s1,s2;
}a[N];
string q1,q2;
long long ans=0; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
	}
	while(q--){
		cin>>q1>>q2;
		int len=q1.size();
		int wz=0,ac=0;
		for(int z=1;z<=n;z++){
			for(int j=0;j<len;j++){
				for(int k=0;k<a[z].s1.size();k++){
					if(a[z].s1[k]==q1[j]){
						ac++;
						if(ac==a[z].s1.size()){
							wz=j;
							break;
						}
					}else{
						ac=0;
					}
				}
			}
			bool f=1;
			for(int i=0;i<len;i++){
				int r=0;
				for(int j=wz-a[z].s1.size();j<=wz;j++){
					if(q2[j]!=a[z].s2[r]){
						 f=0;
						 break;
					}else{
						r++;
					}
				}
			}
			if(f){
				ans++;
			}	
		}
		cout<<ans<<endl;
		ans=0;
	}
	
} 
