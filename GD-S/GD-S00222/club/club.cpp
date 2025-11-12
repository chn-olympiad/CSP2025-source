#include<bits/stdc++.h>
using namespace std;
pair <int,int> p[105];//左边是组别，右边是好感度 
int a[1005],b[105],c[105],ls,ls1,sz=0,ans=0,chaochu[1005],cc=0,a1=0,b1=0,c1=0;
bool cmp(pair<int,int> p1,pair<int,int> p2){
	if(p1.first==p2.first&& p1.second!=p2.second) return p1.second>p2.second;
	else if(p1.first!=p2.first) return p1.first<p2.first;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,ans1=1,ans2=1;
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
			ls=max(b[i],c[i]);
			p[i].second=max(a[i],ls);
			if(p[i].second==a[i]) p[i].first=i*10+1;
			else if(p[i].second==b[i]) p[i].first=i*10+2;
			else p[i].first=i*10+3;
		}
		sort(p,p+n+1,cmp);
		cout<<p[3].second<<endl;
		if(b[0]==0){
			for(int i=0;i<n;i++){
				ans+=a[i];
			}
			
		}
		
		
		else{
			for(int i=0;i<=n;i++){
				cout<<i<<endl;
				if(p[i].first%10==1 && ans1<=n/2){
//					cout<<"进入if"<<endl; 
					ans1+=1;
//					if(ans1<=n/2){
						ans+=p[i].second;
//						cout<<p[i].second;
//					}	
				}
				else if(p[i].first%10==1 && ans1>n/2 && ans2<=n/2){
//					cout<<"进入if2"<<endl; 
					ans2++;
					ans+=b[(p[i].first-1)/10];
//					cout<<(p[i].first-1)/10<<" "<<b[(p[i].first-1)/10]<<" ";
				}
				else if(p[i].first==2 && ans2<=n/2){
//					cout<<"进入if3"<<endl; 
					ans2++;	
					ans+=p[i].second;
//					cout<<p[i].second<<"  ";				
				}
				else if(p[i].first==2 && ans2>n/2){
//					cout<<"进入if4"<<endl; 
					ans+=0;
				}
			}
		}
		cout<<ans<<endl; 
	}
}
