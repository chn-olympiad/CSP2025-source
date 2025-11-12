#include<bits/stdc++.h>
using namespace std;
int rn[100005],chs[4],dtl[100005],p[100005];
long long ans,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		for(int i=1;i<=n;i++){
			rn[i]=0;
			dtl[i]=0;
			p[i]=0;
		}
		chs[1]=chs[2]=chs[3]=0;
		ans=0;
		int a,b,c;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			int max1=max(max(a,b),c),max2;
			if(max1==a){
				max2=max(b,c);
				chs[1]++;
				dtl[i]=1;
			}
			else if(max1==b){
				max2=max(a,c);
				chs[2]++;
				dtl[i]=2;
			}
			else if(max1==c){
				max2=max(a,b);
				chs[3]++;
				dtl[i]=3;
			}
			rn[i]=max1-max2;
			ans+=max1;
		}
		int max3=max(max(chs[1],chs[2]),chs[3]);
		int fr,cnt=1;
		if(max3==chs[1]){
			fr=1;
		}else if(max3==chs[2]){
			fr=2;
		}else{
			fr=3;
		}
		for(int i=1;i<=n;i++){
			if(dtl[i]==fr){
				p[cnt]=rn[i];
				cnt++;
			}
		}
		int over=max3-(n/2);
		if(over<=0){
			cout<<ans<<"\n";
			continue;
		}else{
			sort(p+1,p+cnt);
			for(int i=1;i<=over;i++){
				ans-=p[i];
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
} 
