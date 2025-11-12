#include<bits/stdc++.h>
using namespace std;
int a[100009],b[100009],c[100009],n,w1,w2,m;
int at,bt,ct;
string a1[2009],a2[2009],s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a1[i]>>a2[i];
	}
	for(int i=0;i<m;i++){
		cin>>s1>>s2;
		int p,b,ans=0,l=s1.size();
		bool tb=1;
		for(int j=0;j<l;j++){
			if(s1[j]!=s2[j]){
				p=j;
				if(tb){
					b=j;
					tb=0;
				}
			}
		}
		p-=b-1;
		for(int j=0;j<n;j++){
			int t=a1[j].size();
			if(t>=p){
				for(int k=max(0,p+b-t);k<=b;k++){
					int tt=-1,tb=1;
					while(++tt<t){
						if(a1[j][tt]!=s1[tt+k]){
							tb=0;
							break;
						}
					}
					tt=-1;
					if(tb==0) continue;
					while(++tt<t){
						if(a2[j][tt]!=s2[tt+k]){
							tb=0;
							break;
						}
					}
					ans+=tb;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
