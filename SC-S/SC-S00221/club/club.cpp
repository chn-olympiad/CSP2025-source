#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int cnt1[N],cnt[10],cnt2[N],r[N],t,e[5]; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n=0,cntn=0;
		long long ans=0;
		cin>>n;
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt,0,sizeof(cnt));
		memset(cnt2,0,sizeof(cnt2));
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			e[1]=a;e[2]=b;e[3]=c;
			sort(e+1,e+4);
			int ma=e[3];
			if(ma==a){
				cnt1[i]=1;
				cnt[1]++;
				ans+=a;
			}
			else if(ma==b){
				cnt1[i]=2;
				cnt[2]++;
				ans+=b;
			}
			else if(ma==c){
				cnt1[i]=3;
				cnt[3]++;
				ans+=c;
			}
			
			cnt2[i]=e[3]-e[2];
			//cout<<cnt2[i]<<endl;
			//cout<<ans<<endl;
		}
		int k,l;
		for(int i=1;i<=3;i++){
			if(cnt[i]>n/2){
				k=i;
				l=cnt[i]-(n/2);
				//cout<<l<<endl;
				break;
			}
			if(i==3){
			cout<<ans<<endl;
			//cout<<1;
			goto p;
		}
		}
		 for(int i=1;i<=n;i++){
		 	if(cnt1[i]==k)r[++cntn]=cnt2[i];
		 }
		 //for(int i=1;i<=cntn;i++)cout<<r[i]<<" ";
		 sort(r+1,r+cntn+1);
		 //cout<<ans<<endl;
		 for(int i=1;i<=l;i++)ans-=r[i]; 
		 cout<<ans<<endl;
		p:;
		
	}
	 return 0;
	}
	