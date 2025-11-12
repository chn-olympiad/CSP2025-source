#include<bits/stdc++.h>
using namespace std;
int n,q;
const int N=2e5+7;
const int M=5e6+7;
string s1,s2,t1,t2;
int u[N];
int len[N],y[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> s1 >> s2;
		len[i]=s1.size();
		int a1,a2;
		for(int j=0;j<len[i];j++){
			if(s1[j]=='b'){
				y[i]=j;
				a1=j;
			}if(s2[j]=='b'){
				a2=j;
			}
		}
		u[i]=a2-a1;
	}
	for(int i=1;i<=q;i++){
		cin >> t1 >> t2;
		int a1,a2;
		for(int j=0;j<t1.size();j++){
			if(t1[j]=='b'){
				a1=j;
			}if(t2[j]=='b'){
				a2=j;
			}
		}
		int lens=t1.size();
		int ans=0;
		for(int j=1;j<=n;j++){
			if(lens>=len[j] && a2-a1==u[j] && len[j]+a1-y[j]<=lens && y[j]<=a1){
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
