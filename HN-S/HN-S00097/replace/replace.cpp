#include<bits/stdc++.h>
using namespace std;
int n,q;
struct e{
	string b1,c1;
}a[20010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].b1>>a[i].c1;
	}
	while(q>0){
		string p1,p2;
		cin>>p1>>p2;
		if(p1.size()!=p2.size()){
			cout<<0<<endl;
			q--;
			continue;
		}
		int l,r,cnt=0;
		for(int i=0;i<p1.size();i++){
			if(p1[i]!=p2[i]&&cnt==0){
				cnt=1;
				l=i;
				r=i;
			}
			if(p1[i]!=p2[i]){
				r=i;
			}
		}
		//cout<<l<<" "<<r<<endl;
		int ans=0;
		for(int w=1;w<=n;w++){
			if(a[w].b1.size()<(r-l+1)){
				continue;
			}
			for(int i=0;i<=l;i++){
				string p3=p1;
				int flag=1;
				for(int j=i;j<i+a[w].b1.size();j++){
					if(a[w].b1[j-i]!=p3[j]){
						flag=0;
						break;
					}
				}
				if(flag==1){
					int flagg=1;
					for(int j=i;j<=r;j++){
						p3[j]=a[w].c1[j-i];
						if(p3[j]!=p2[j]){
							flagg=0;
							break;
						}
					}
					if(flagg==1){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
		
		
		q--;
	}
}
// Ren5Jie4Di4Ling5%
