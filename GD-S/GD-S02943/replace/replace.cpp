#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
int n,q;
string a[N],b[N],a1,b1;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	for(int i=1;i<=q;i++){
		cin>>a1>>b1;
		long long ans=0;
		for(int i=1;i<=n;i++){
			int pos=a1.find(a[i],0);
			while(pos!=-1){
				string t=a1;
				t.replace(pos,b[i].size(),b[i]);
				if(t==b1)ans++;
				pos=a1.find(a[i],pos+1);
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
