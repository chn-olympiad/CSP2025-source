#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,ida=-1,idb=-1;
	scanf("%d%d",&n,&q);
	cin>>a>>b;
	int la=a.length();
	int lb=b.length();
	for(int i=0;i<la;i++){
		if(a[i]=='b'){
			ida=i;
		}
	}
	for(int i=0;i<lb;i++){
		if(b[i]=='b'){
			idb=i;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>c>>d;
		int lc=c.length();
		bool flag=0,flagg=0;
		int s=0,id=-1;
		for(int j=0;j<lc;j++){
			if(c[j]!='a'&&c[j]!='b'){
				flag=1;
				break;
			}
			if(c[j]=='b'){
				s++;
				if(s>1){
					flag=1;
					break;
				}
				id=j;
				if(id>ida){
					flag=1;
					break;
				}
			}
		}
		if(flag==0){
			if(lc-id>la-ida){
				flag=1;
			}
		}
		int ld,idd=-1;
		s=0;
		ld=d.length();
		for(int j=0;j<ld;j++){
			if(d[j]!='a'&&d[j]!='b'){
				flagg=1;
				break;
			}
			if(d[j]=='b'){
				s++;
				if(s>1){
					flag=1;
					break;
				}
				idd=j;
				if(idd>idb){
					flag=1;
					break;
				}
			}
		}
		if(flag==0){
			if(ld-idd>lb-idb){
				flagg=1;
			}
		}
		if(flag==0&&flagg==0){
			ans=0;
		}
	}
	printf("%d",ans);
	return 0;
}
