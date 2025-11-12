#include<bits/stdc++.h>
using namespace std;
int n,q,ans,la,ff;
string s1,s2;
string a,b;
string x,xx,y,yy;
map<string,string>m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		m[s1]=s2;
	}
	while(q--){
		ans=0;
		cin>>a>>b;
		la=a.size();
		x='/';xx='/';
		for(int i=0;i<la;i++){
			if(i>0)x+=a[i-1];
			if(i>0)xx+=b[i-1];
			if(x==xx){
				//cout<<x<<" x "<<xx<<endl;
				for(int j=i;j<la;j++){
					y=a[i];
					yy=b[i];
					for(int l=i+1;l<=j;l++){
						y+=a[l];
						yy+=b[l];
					}
					//cout<<y<<" "<<yy<<" "<<m[y]<<endl;
					if(m[y]==yy){
						ff=1;
						if(ff){
							for(int l=j+1;l<la;l++){
								if(a[l]!=b[l]){
									ff=0;
									break;
								}
							}
						}
						ans+=ff;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
