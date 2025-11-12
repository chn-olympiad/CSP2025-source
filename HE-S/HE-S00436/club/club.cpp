#include<bits/stdc++.h>
using namespace std;

long long t,n,ans; 
const int MAXN=100005;
long long club[5],a1[MAXN],a2[MAXN],a3[MAXN];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		memset(club,0,sizeof(club));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		long long cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			cnt1+=a1[i];
			cnt2+=a2[i];
			cnt3+=a3[i];	
		}
		
		if(n==2){
			int num1=a1[1]+a2[2];
			int num2=a1[1]+a3[2];
			int num3=a2[1]+a1[2];
			int num4=a2[1]+a3[2];
			int num5=a3[1]+a1[2];
			int num6=a3[1]+a2[2];
			ans=max({num1,num2,num3,num4,num5,num6});
		}
		
		else if(cnt2==0 && cnt3==0){
			sort(a1+1,a1+1+n,cmp);
			for(int i=1;i<=n/2;i++)	ans+=a1[i];  //ÌØÊâÐÔÖÊA 
		}
		else if(cnt1==0 && cnt2==0){
			sort(a3+1,a3+1+n,cmp);
			for(int i=1;i<=n/2;i++)	ans+=a3[i]; 
		}
		else if(cnt1==0 && cnt3==0){
			sort(a2+1,a2+1+n,cmp);
			for(int i=1;i<=n/2;i++)	ans+=a2[i]; 
		}

		else if(cnt2!=0 && cnt3==0){
			for(int i=1;i<=n;i++){
				if(a1[i]>=a2[i]){
					club[1]++;
					ans+=a1[i];
				}
				else{
					club[2]++;
					ans+=a2[i];
				}
			}
//			if(club[1]>n/2 || club[2]>n/2){
//				int cha=max(club[1],club[2])-n/2;
//				for(int i=1;i<=n;i++){
//					int chazhi[MAXN];
//					int tem=a1[i]-a2[i];
//					if(tem<0)	tem=tem*-1;
//					chazhi[i]=tem;
//					sort(chazhi+1,chazhi+n+1,cmp);
//					ans=ans-chazhi[1];
//				}
//			}
		}
		else{
			for(int i=1;i<=n;i++){
				long long choose=max({a1[i],a2[i],a3[i]});
				if(choose==a1[i]){
					club[1]++;
					ans+=a1[i];
				}	
				else if(choose==a2[i]){
					club[2]++;
					ans+=a2[i];
				}	
				else if(choose==a3[i]){
					club[3]++;
					ans+=a3[i];
				}	
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
