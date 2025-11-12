#include<bits/stdc++.h>
using namespace std;
#define N 200005
inline int read(){
	int a=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=a*10+c-'0';
		c=getchar();
	}
	return f*a;
}
int n,q;
string c1[N],c2[N];
int len[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++)cin>>c1[i]>>c2[i],len[i]=c1[i].size();
	while(q--){
		string cs,ct;
		cin>>cs>>ct;
		int k1=cs.size(),k2=ct.size();
		if(k1!=k2){
			printf("0\n");
			continue;
		}
		int ans=0;
		for(int i=0;i<k1;i++)
			for(int j=1;j<=n;j++){
				if(len[j]+i-1>=k1)continue;
				bool f=1;
				for(int k=0;k<len[j];k++)
					if(c1[j][k]!=cs[i+k]||c2[j][k]!=ct[i+k]){
						f=0;
						break;
					}
				if(f==0)continue;
				for(int k=i+len[j];k<k1;k++)
					if(cs[k]!=ct[k]){
						f=0;
						break;
					}
				if(f==0)continue;
				for(int k=0;k<i;k++)
					if(cs[k]!=ct[k]){
						f=0;
						break;
					}
				ans+=f;
			}
		printf("%d\n",ans);
	}
	return 0;
}
