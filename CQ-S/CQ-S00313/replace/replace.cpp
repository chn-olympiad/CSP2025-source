#include<bits/stdc++.h>
using namespace std;
struct s{
	string s1,s2;
}a[200005],b[200005],c[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
		
	}
	for(int i=1;i<=q;i++){
		cin>>b[i].s1>>b[i].s2;
		int m=0,ans=0;
			m=0;
			for(int j=1;j<=max(b[i].s1.size(),b[i].s2.size());j++){
				if(b[i].s1[j]!=b[i].s2[j]){
					int f=0;
					for(int k=1;k<=n;k++){
						for(int l=1;l<=a[k].s1.size();l++){
							if(a[k].s1[l]==b[i].s1[j]&&a[k].s2[l]==b[i].s2[j]){
								f=1;
								a[k].s1[l]='0';
								a[k].s2[l]='0';
								break;
							}
						}
						if(f==1){
							break;
						}
					}
					if(f!=1){
						m=0;
						break;
					}
					else{
						m=1;
					} 
				}
			}
			if(m==1){
				ans++;
			}
		cout<<ans<<"\n";
	}
	return 0;
} 
