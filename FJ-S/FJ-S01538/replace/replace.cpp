#include<bits/stdc++.h>
using namespace std;
string s1[200005],s2[200005];
int s[200005],l[200005],r[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	int ans=0;
	if(n<=100&&q<=100){
		while(q--){
			ans=0;
			string t1,t2,t12;
			cin>>t1>>t2;
			for(int i=1;i<=n;i++){
				for(int j=0;j<(int)(t1.size());j++){
					bool flag=0;
					for(int k=j;k<j+(int)(s1[i].size());k++){
						if(s1[i][k-j]!=t1[k]){
							flag=1;
							break;
						}
					}
					if(!flag){
						for(int k=0;k<(int)(t1.size());k++){
							if(k>=j&&k<j+(int)(s1[i].size())) t12[k]=s2[i][k-j];
							else t12[k]=t1[k];
						}
						for(int k=0;k<(int)(t1.size());k++){
							if(t12[k]!=t2[k]){
								flag=1;
								break;
							}
						}
					}
					if(!flag) ans++;
				}			
			}
			cout<<ans<<"\n";
		}		
	}else{
		int x,y;
		for(int i=1;i<=n;i++){
			for(int j=0;j<(int)(s1[i].size());j++){
				if(s1[i][j]=='b'){
					x=j;
					l[i]=j;
					r[i]=(int)(s1[i].size())-j-1;
				}
			}
			for(int j=0;j<(int)(s1[i].size());j++){
				if(s2[i][j]=='b'){
					y=j;
				}
			}
			s[i]=x-y;
		}
		while(q--){
			string t1,t2;
			cin>>t1>>t2;
			for(int i=0;i<(int)(t1.size());i++){
				if(t1[i]=='b'){
					x=i;
				}
			}
			for(int i=0;i<(int)(t1.size());i++){
				if(t2[i]=='b'){
					y=i;
				}
			}
			for(int i=1;i<=n;i++){
				if(s[i]==x-y&&l[i]<=x&&r[i]<=(int)(t1.size())-x-1) ans++;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
