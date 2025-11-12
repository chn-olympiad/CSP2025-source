#include <bits/stdc++.h>//人杰地灵 
using namespace std;
int t,ans,tem,sum,n,a[100086],b[100086],c[100086],aa[100086],bb[100086],cc[100086],aj,bj,cj,ag,bg,cg,uu;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++){
		memset(aa,0,sizeof(aa));
		memset(bb,0,sizeof(bb));
		memset(cc,0,sizeof(cc));
		aj=0;
		bj=0;
		cj=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i]>>b[i]>>c[i];
		for(int i=1;i<=n;i++){
			uu=max(a[i],max(b[i],c[i]));
			ans+=uu;
			if(uu==a[i]&&aj<n/2){
				aj++;
				aa[aj]=uu;
				continue;
			}
			else{
				if(uu==b[i]&&bj<n/2){
					bj++;
					bb[bj]=uu;
					continue;
				}
				else if(uu==c[i]&&cj<n/2){
					cj++;
					cc[cj]=uu;
					continue;
				}
			}		
			ans-=uu;
			sort(aa+1,aa+1+aj);
			sort(bb+1,bb+1+bj);
			sort(cc+1,cc+1+cj);
			ag=a[i]-aa[1];
			bg=b[i]-bb[1];
			cg=c[i]-cc[1];
			uu=max(ag,max(bg,cg));
			if(uu>0)	ans+=uu;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

