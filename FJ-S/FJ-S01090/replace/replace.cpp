#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,q;
string s1[N],s2[N],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(q--){
		cin>>t1>>t2;
		int tsiz=t1.size(),ans=0;
		for(int l=0;l<tsiz;l++){
			for(int r=0;r<tsiz;r++){
				int ok=1;
				for(int i=0;i<tsiz;i++){
					if(i<l||i>r){
						if(t1[i]!=t2[i]) ok=0;
					}
				}
				if(ok==0) continue;
				for(int i=1;i<=n;i++){
					if(s1[i].size()==r-l+1){
						int f=1;
						for(int a=0,b=l;b<=r;a++,b++){
							if(s1[i][a]!=t1[b]||s2[i][a]!=t2[b])f=0; 
						}
						if(f==1) ans++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}