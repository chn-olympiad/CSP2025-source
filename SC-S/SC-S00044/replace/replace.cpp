#include<bits/stdc++.h>
using namespace std;
int n,q,ans,s;
string a[200010],b[200010];
string q1,q2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++){
		cin>>q1>>q2;
		ans=0;
		for(int l=1;l<=q1.length();l++){
			for(int r=2;r<=q1.length();r++){
				for(int t=1;t<=n;t++){
					if(q1[r]==a[t][r]&&q1[l]==a[t][l]){
						for(int ii=l;ii<=r;ii++){
							q1[ii]=b[t][ii-l];
						}
						if(q1==q2){
							ans++;
						}
					}
				}
			
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}