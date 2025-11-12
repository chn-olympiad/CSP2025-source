//GZ-S00116 茶城中学 唐浩然
#include <bits/stdc++.h>
using namespace std;
struct my{
	int a,b,c;
}yg[100000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,ans=0,z=0,p=0,o=0;
	cin>>t;
	for(int p=1;p<=t;p++){
		cin>>n;
		for(int i=1;i<=n;i++){
			yg[i].a=0;
			yg[i].b=0;
			yg[i].c=0;
			cin>>yg[i].a>>yg[i].b >>yg[i].c;
		}
		
		for(int i=1;i<=n;i++){
			if(z<=n/2&&p<=n/2&&o<=n/2){
				ans+=max(max(yg[i].a,yg[i].b),yg[i].c);
				if(yg[i].a>yg[i].b&&yg[i].a>yg[i].c){
					z++;
				}if(yg[i].b>yg[i].a&&yg[i].b>yg[i].c){
					p++;
				}if(yg[i].c>yg[i].b&&yg[i].c>yg[i].a){
					o++;
				}
			}else if(z<=n/2&&o<=n/2){
				ans+=max(yg[i].a,yg[i].c);
				if(yg[i].a>yg[i].c){
					z++;
				}if(yg[i].c>yg[i].a){
					o++;
				}
			}else if(p<=n/2&&o<=n/2){
				ans+=max(yg[i].b,yg[i].c);
				if(yg[i].b>yg[i].c){
					p++;
				}if(yg[i].c>yg[i].b){
					o++;
				}
			}else if(z<=n/2&&p<=n/2){
				ans+=max(yg[i].a,yg[i].b);
				if(yg[i].a>yg[i].b){
					z++;
				}if(yg[i].b>yg[i].a){
					p++;
				}
			}else if(z<=n/2){
				ans+=yg[i].a;
				z++;
			}else if(p<=n/2){
				ans+=yg[i].b;
				p++;
			}
			else if(o<=n/2){
				ans+=yg[i].c;
				o++;
			}
		}
		cout<<ans;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}

