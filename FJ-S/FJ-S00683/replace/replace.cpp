#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,q;
string s[N],s1[N],y,e;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>s1[i];
	}
	for(int i=1;i<=q;i++){
		cin>>y>>e;
		int sum=0;
		for(int j=1;j<=n;j++){
			if(y==s[j]){
				sum++;
			}else{
				int jie=0,wei=0,jie1=0,wei1=0;
				for(int k=0;k<y.size();k++){
					string qq;
					for(int l=k;l<k+s[j].size();l++){
						qq+=y[l];
					}
					if(qq==s[j]){
							jie=k,wei=k+s[j].size();
					    }
				}
				for(int k=0;k<e.size();k++){
					string qq;
					for(int l=k;l<k+s1[j].size();l++){
						qq+=e[l];
					}
					if(qq==s1[j]){
							jie1=k,wei1=k+s[j].size();
					}
				}
				if(jie==jie1&&wei==wei1){
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
