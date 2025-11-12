#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
#define endl "\n"
using namespace std;
int T,n,ans,cnt1,cnt2,cnt3;
int a[100010][5]; 
inline int min(int x,int y){return x<y?x:y;}
inline int max(int x,int y){return x>y?x:y;}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q1,q2,q3;
		cnt1=0,cnt2=0,cnt3=0;
		ans=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%lld",&a[i][j]);
			}
		}
		for(int i=1;i<=n;i++){
			int tmp=max(a[i][1],max(a[i][2],a[i][3]));
			if(a[i][1]==tmp)q1.push(make_pair(a[i][1]-max(a[i][2],a[i][3]),i)),cnt1++;
			else if(a[i][2]==tmp)q2.push(make_pair(a[i][2]-max(a[i][1],a[i][3]),i)),cnt2++;
			else q3.push(make_pair(a[i][3]-max(a[i][1],a[i][2]),i)),cnt3++;
			ans+=tmp;
		}
		if(cnt1<n/2 && cnt2<n/2 && cnt3<n/2)printf("%lld\n",ans);
		else{
			if(cnt1>cnt2 && cnt1>cnt3){
				while(cnt1>n/2){
					ans-=q1.top().first;
					cnt1--;
					int x=q1.top().second;
					q1.pop();
					if(a[x][2]>a[x][3]){
						cnt2++;
						q2.push(make_pair(a[x][2]-a[x][3],2));
					}else{
						cnt3++;
						q3.push(make_pair(a[x][3]-a[x][2],3));
					}
				}while(cnt2>n/2){
					ans-=q2.top().first;
					cnt2--;
					int x=q2.top().second;
					cnt3++;
					q3.push(make_pair(a[x][3]-a[x][3],3));
				}				
			}else if(cnt2>cnt3 && cnt2>cnt1){
				while(cnt2>n/2){
					ans-=q2.top().first;
					cnt2--;
					int x=q2.top().second;
					q2.pop();
					if(a[x][1]>a[x][3]){
						cnt1++;
						q1.push(make_pair(a[x][1]-a[x][3],1));
					}else{
						cnt3++;
						q3.push(make_pair(a[x][3]-a[x][1],3));
					}
				}while(cnt1>n/2){
					ans-=q1.top().first;
					cnt1--;
					int x=q1.top().second;
					cnt3++;
					q3.push(make_pair(a[x][3]-a[x][3],3));
				}			
			}else{
				while(cnt3>n/2){
					ans-=q3.top().first;
					cnt3--;
					int x=q3.top().second;
					q3.pop();
					if(a[x][2]>a[x][1]){
						cnt2++;
						q2.push(make_pair(a[x][2]-a[x][1],2));
					}else{
						cnt1++;
						q1.push(make_pair(a[x][1]-a[x][2],1));
					}
				}while(cnt2>n/2){
					ans-=q2.top().first;
					cnt2--;
					int x=q2.top().second;
					cnt1++;
					q3.push(make_pair(a[x][1]-a[x][1],1));
				}
			} 

			printf("%lld\n",ans);
		}
	}
	return 0;
}	
