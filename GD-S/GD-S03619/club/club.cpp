#include<bits/stdc++.h>
using namespace std;
long long t,n,a,b,c,tr,ans,sum=0;
long long sa[100011][10];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=a=b=c=0;
		for(int i=1;i<=n;i++){
			cin>>sa[i][1]>>sa[i][2]>>sa[i][3];
			sa[i][4]=max(sa[i][1],max(sa[i][2],sa[i][3]));
			ans+=sa[i][4];
			if(sa[i][4]==sa[i][1]){
				a++;
				sa[i][0]=1;
				sa[i][5]=min(sa[i][1]-sa[i][2],sa[i][1]-sa[i][3]);
			}
			else if(sa[i][4]==sa[i][2]){
				b++;
				sa[i][0]=2;
				sa[i][5]=min(sa[i][2]-sa[i][1],sa[i][2]-sa[i][3]);
			}
			else if(sa[i][4]==sa[i][3]){
				c++;
				sa[i][0]=3;
				sa[i][5]=min(sa[i][3]-sa[i][2],sa[i][3]-sa[i][1]);
			}
		}
		if(a<n/2 && b<n/2 && c<n/2)cout<<ans<<endl;
		else{
			while(a>(n/2)){
				tr=1;
				for(int i=2;i<=n;i++){
					if(sa[i][0]!=1) continue;
					if(sa[tr][5]>sa[i][5]) tr=i;
				}
				ans-=sa[tr][5];
				sa[tr][5]=22222;
				a--;
			}
			while(b>(n/2)){
				tr=1;
				for(int i=2;i<=n;i++){
					if(sa[i][0]!=2) continue;
					if(sa[tr][5]>sa[i][5]) tr=i;
				}
				ans-=sa[tr][5];
				sa[tr][5]=22222;
				b--;
			}
			while(c>(n/2)){
				tr=1;
				for(int i=2;i<=n;i++){
					if(sa[i][0]!=3) continue;
					if(sa[tr][5]>sa[i][5]) tr=i;
				}
				ans-=sa[tr][5];
				sa[tr][5]=22222;
				c--;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
