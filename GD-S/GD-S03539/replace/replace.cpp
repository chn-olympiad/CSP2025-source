#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
map<int,int>tr[5000005];
int n,q,gs[5000005],tot=1;
long long ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	string s1,s2;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int sd=s1.size();
		s1='0'+s1,s2='0'+s2;
		int dd=1;
		for(int j=1;j<=sd;j++){
			int dz=(s1[j]-'a')*26+s2[j]-'a';
			if(!tr[dd][dz]){
				dd=tr[dd][dz]=++tot;
			}
			else dd=tr[dd][dz];
		}
		gs[dd]++;
	}
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		int sd=s1.size();
		s1='0'+s1,s2='0'+s2;
		int zh=0;
		for(int j=sd;j>=1;j--){
			if(s1[j]!=s2[j]){
				zh=j;break;
			}
		}
		int dd=1;
		ans=0;
		for(int jj=1;jj<=sd;jj++){
			dd=1;
			for(int j=jj;j<=sd;j++){
				int dz=(s1[j]-'a')*26+s2[j]-'a';
				if(tr[dd].find(dz)==tr[dd].end()){
//					cout<<j<<endl;
					break;
				}
				else {
					dd=tr[dd][dz];
					if(j>=zh)ans+=gs[dd];
//					cout<<j<<' '<<s1[j]<<";"<<gs[dd]<<endl;
				}
			}
//			cout<<jj<<' '<<ans<<endl;
			if(s1[jj]!=s2[jj])break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
