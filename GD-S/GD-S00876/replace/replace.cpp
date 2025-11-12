#include<bits/stdc++.h>
using namespace std;
string st1[105],st2[105];
int st[105],sz[105];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	if(n<=100&&q<=100){
		for(int i=1;i<=n;i++){
			cin>>st1[i]>>st2[i];
			sz[i]=st1[i].size();
			for(int j=0;j<sz[i];j++){
				if(st1[i][j]!=st2[i][j]){
					st[i]=j;
					break;
				}
			}
		}
		while(q--){
			string T1,T2;
			cin>>T1>>T2;
			int sum=0,dis,s=T1.size();
			if(T1.size()!=T2.size()){
				puts("0");
				continue;
			}
			for(int i=0;i<s;i++){
				if(T1[i]!=T2[i]){
					dis=i;
					break;
				}
			}
			for(int i=1;i<=n;i++){
				if(dis+sz[i]-st[i]<=s){
					bool f=1;
					for(int j=dis;j<s;j++){
						if(j<dis+sz[i]&&(T1[j]!=st1[i][j-dis+st[i]]||T2[j]!=st2[i][j-dis+st[i]])) f=0;
						if(j>=dis+sz[i]&&T1[j]!=T2[j]) f=0;
					}
					sum+=f;
				}
			}
			cout<<sum<<"\n";
		}
	}
	return 0;
}
//shui le 10 pts qwq
