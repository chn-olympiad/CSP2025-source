#include<bits/stdc++.h>
using namespace std;
int T,h[100001],d[50001];
struct student{
	int one,two,three;
}s[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		int n;
		cin>>n;
		int m=n/2,yi=0,er=0,san=0,ans=0;
		for(int j=1;j<=n;j++) h[j]=0;
		for(int j=1;j<=n;j++){
			cin>>s[j].one>>s[j].two>>s[j].three;
			if(s[j].one>=s[j].two&&s[j].one>=s[j].three){
				h[j]=1;yi++;ans+=s[j].one;
			}
			else if(s[j].two>s[j].one&&s[j].two>=s[j].three){
				h[j]=2;er++;ans+=s[j].two;
			}
			else if(s[j].three>s[j].one&&s[j].three>s[j].two){
				h[j]=3;san++;ans+=s[j].three;
			}
		}
		if(yi>m){
			int D=yi-m,zhi=0;
			for(int j=1;j<=n;j++){
				if(h[j]==1){
					if(s[j].two>=s[j].three){
						d[++zhi]=s[j].one-s[j].two;
					}
					else{
						d[++zhi]=s[j].one-s[j].three;
					}
				}
			}
			stable_sort(d+1,d+zhi+1);
			for(int j=1;j<=D;j++){
				ans-=d[j];
			}
		}
		if(er>m){
			int D=er-m,zhi=0;
			for(int j=1;j<=n;j++){
				if(h[j]==2){
					if(s[j].one>=s[j].three){
						d[++zhi]=s[j].two-s[j].one;
					}
					else{
						d[++zhi]=s[j].two-s[j].three;
					}
				}
			}
			stable_sort(d+1,d+zhi+1);
			for(int j=1;j<=D;j++){
				ans-=d[j];
			}
		}
		if(san>m){
			int D=san-m,zhi=0;
			for(int j=1;j<=n;j++){
				if(h[j]==3){
					if(s[j].two>=s[j].one){
						d[++zhi]=s[j].three-s[j].two;
					}
					else{
						d[++zhi]=s[j].three-s[j].one;
					}
				}
			}
			stable_sort(d+1,d+zhi+1);
			for(int j=1;j<=D;j++){
				ans-=d[j];
			}
		}
		cout<<ans<<endl;
		/*for(int j=1;j<=n;j++)cout<<h[j]<<" ";
			cout<<endl<<yi<<er<<san;*/

	}
}