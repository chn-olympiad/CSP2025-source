#include<bits/stdc++.h>
using namespace std;
int T,n,n1=0,n2=0,n3=0,ans=0;
bool b1=1,b2=1,b3=1;
struct node{
	int g1,g2,g3,mg,nmg,mcg,nmcg;
}a[10005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].g1>>a[i].g2>>a[i].g3;
			a[i].mg=max(max(a[i].g1,a[i].g2),a[i].g3);
			if(max(max(a[i].g1,a[i].g2),a[i].g3)==a[i].g1){
				a[i].nmg=1;
				a[i].mcg=max(a[i].g2,a[i].g3);
				if(max(a[i].g2,a[i].g3)==a[i].g2)
					a[i].nmcg=2;
				else
					a[i].nmcg=3;
			}
			else if(max(max(a[i].g1,a[i].g2),a[i].g3)==a[i].g2){
				a[i].nmg=2;
				a[i].mcg=max(a[i].g1,a[i].g3);
				if(max(a[i].g1,a[i].g3)==a[i].g1)
					a[i].nmcg=1;
				else
					a[i].nmcg=3;
			}
			else{
				a[i].nmg=3;
				a[i].mcg=max(a[i].g1,a[i].g2);
				if(max(a[i].g1,a[i].g2)==a[i].g1)
					a[i].nmcg=1;
				else
					a[i].nmcg=2;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i].mg>a[j].mg)
					swap(a[i],a[j]);
			}
		}
		for(int i=1;i<=n;i++){
			if((a[i].nmg==1&&b1)||(a[i].nmg==2&&!b2&&b1&&a[i].nmcg==1)||(a[i].nmg==3&&!b3&&b1&&a[i].nmcg==1)||(!b2&&!b3)){
				n1++;
				ans+=a[i].g1;
				if(n1==n/2)b1=0;
			}
			else if((a[i].nmg==2&&b2)||(a[i].nmg==1&&!b1&&b2&&a[i].nmcg==2)||(a[i].nmg==3&&!b3&&b2&&a[i].nmcg==2)||(!b1&&!b3)){
				n2++;
				ans+=a[i].g2;
				if(n2==n/2)b2=0;
			}
			else{
				n3++;
				ans+=a[i].g3;
				if(n3==n/2)b3=0;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
