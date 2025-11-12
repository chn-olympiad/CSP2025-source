#include<bits/stdc++.h>
using namespace std;
int vis[10000010],n,q,biao,cnt,a,b;
string s1[200010],s2[200010],u,v;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	biao=0;
	for(int i=1; i<=n; i++) {
		cin>>s1[i]>>s2[i];
		if(biao==0) {
			for(int j=0; j<s1[i].size(); j++) {
				//cout<<s1[i][j]<<" ";
				if(s1[i][j]!='a'&&s1[i][j]!='b') {
					//cout<<i<<" ";
					biao=1;
					break;
				}
				
				if(s1[i][j]=='b') cnt++;
			}
			if(biao==0) {
				for(int j=0; j<s2[i].size(); j++) {
					if(s2[i][j]!='a'&&s2[i][j]!='b') {
					//	cout<<i<<" ";
						biao=1;
						break;
					}
					if(s2[i][j]=='b') cnt++;
				}
			}
		}
	}
	if(cnt==n*2&&biao==0) {
		for(int i=1;i<=n;i++){
			a=s1[i].find('b');
			b=s2[i].find('b');
			//cout<<abs(a-b)<<endl;
			vis[b-a+5000000]++;
		}
		for(int i=1;i<=q;i++){
			cin>>u>>v;
			a=u.find('b');
			b=v.find('b');
			printf("%d\n",vis[b-a+5000000]);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
