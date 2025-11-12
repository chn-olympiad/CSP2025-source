#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string a[N],b[N],L[N],R[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i]; 
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int l1=t1.size(),ans=0;
		L[0]=t1[0];
		for(int i=1;i<l1;++i)L[i]=L[i-1]+t1[i];
		R[l1-1]=t1[l1-1];
		for(int i=l1-2;i>=0;--i)R[i]=t1[i]+R[i+1];
		for(int i=1;i<=n;++i){
			int la=a[i].size();
			for(int j=0;j<l1-la;++j){
				if(t1[j]!=a[i][0])continue;
				int dt=1;
				while(dt<la&&t1[j+dt]==a[i][j+dt])dt++;
				if(dt>=la){
					if(j==0&&(b[i]+R[dt])==t2)ans++;
					if(j!=0&&(L[j-1]+b[i]+R[j+dt])==t2)ans++;
				}
				j+=dt;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
