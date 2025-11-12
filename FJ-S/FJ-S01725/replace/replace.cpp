#include<iostream>
#include<cstdio>
using namespace std;
string a[1001][2],b[2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,ans=0;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1];
	}
	for(int i=1;i<=q;i++){
		cin>>b[0]>>b[1];
		ans=0;
		int k=b[0].size();
		if(b[0].size()!=b[1].size()) cout<<0<<'\n';
		else{
			int l=0,r=k-1;
			while(l<k&&b[0][l]==b[1][l]) l++;
			while(r>l&&b[0][r]== b[1][r]) r--;
			//cout<<l<<' '<<r<<'\n';
			if(r<l){
				for(int x=0;x<k;x++){
					for(int y=x;y<k;y++){
						for(int i=1;i<=n;i++){
							if(b[0].substr(x,y-x+1)==a[i][0]){
								if(b[1].substr(x,y-x+1)==a[i][1]){
									ans++;
								}
							}
						}
					}
				}
			}else{
				for(int x=0;x<=l;x++){
					for(int y=r;y<k;y++){
						for(int i=1;i<=n;i++){
							if(b[0].substr(x,y-x+1)==a[i][0]){
								if(b[1].substr(x,y-x+1)==a[i][1]){
									//cout<<b[0].substr(x,y-x+1)<<" "<<a[i][0]<<" "<<b[1].substr(x,y-x+1)<<" "<<a[i][1]<<'\n';
									ans++;
								}
							}
						}
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
