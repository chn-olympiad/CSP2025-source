#include<bits/stdc++.h>
const int N=2e5+5;
using namespace std;
int n,q,k,st,ed,l1,l2,l[3][N],ans;
string s[3][N],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[1][i]>>s[2][i];
		l[1][i]=s[1][i].size(),l[2][i]=s[2][i].size();
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		l1=t1.size(),l2=t2.size(),ans=0;
		for(int j=0;j<min(l1,l2);j++){
			if(t1[j]!=t2[j]){st=j;break;}
		}
		for(int j=1;j<=min(l1,l2);j++){
			if(t1[l1-j]!=t2[l2-j]){ed=l1-j;break;}
		}
		for(int j=1;j<=n;j++){
			if(l[1][j]-l[2][j]!=l1-l2)continue;
			if(l[1][j]<ed-st+1)continue;
			for(int p=0,q=p+l[1][j]-1;p<=st&&q<l1;p++,q++){
				if(!(ed<=q))continue;
				bool f=false;
				for(int z=p;z<=q;z++){
					if(t1[z]!=s[1][j][z-p]){f=true;break;}
				}
				if(f==false){
					for(int z=p;z<=p+l[2][j]-1;z++){
						if(t2[z]!=s[2][j][z-p]){f=true;break;}
					}
					if(f==false)ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}//10
