#include<bits/stdc++.h>
using namespace std;
struct node{
	long long id,w,m;
}t[100005];
bool cmp(node x,node y){
	return x.w>y.w;
}
long long T,n,a[500005],b[500005],c[500005],zt[500005];
vector<long long> za,zb,e;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
	    cin>>n;
	    long long flag_A=1,flag_B=1;
		for(long long i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0||c[i]!=0) flag_A=0;
			if(c[i]!=0) flag_B=0;
		}
		if(flag_A==1){
			sort(a+1,a+n+1);
			long long sum=0; 
			for(long long i=n;i>n/2;i--){
				sum+=a[i];
				//cout<<i<<endl;
			} 
			cout<<sum<<endl;
		}else if(flag_B==1){
			long long sum=0,asum=0,bsum=0;
			for(long long i=1;i<=n;i++){
				if(a[i]>b[i]){
					t[i].m=1;
				}else if(a[i]==b[i]){
					t[i].m=2;
				}else{
					t[i].m=3;
				}
				t[i].w=abs(a[i]-b[i]);
				t[i].id=i;
			}
			sort(t+1,t+n+1,cmp);
			for(long long i=1;i<=n;i++){
				//cout<<i<<endl;
				if(t[i].m==1&&asum<n/2){
					asum++;
					sum+=a[t[i].id];
				}else if(t[i].m==1&&asum>=n/2){
					bsum++;
					sum+=b[t[i].id];
				}else if(t[i].m==3&&bsum<n/2){
					bsum++;
					sum+=b[t[i].id];
				}else if(t[i].m==3&&bsum>=n/2){
					asum++;
					sum+=a[t[i].id];
				}else{
					sum+=a[t[i].id];
				}
			}
			cout<<sum<<endl;
		/////////////////////////////////////////////////////////
		}else{
			long long sum=0,asum=0,bsum=0,csum=0;
			for(long long i=1;i<=n;i++){
				if(a[i]>=b[i]&&a[i]>=c[i]){
					asum++;
					sum+=a[i];
				}else if(b[i]>a[i]&&b[i]>=c[i]){
					bsum++;
					sum+=b[i];
				}else if(c[i]>b[i]&&c[i]>a[i]){
					csum++;
					sum+=c[i];
				}else{
					sum+=min(a[i],min(b[i],c[i]));
				}
				//cout<<"ddd:"<<sum<<endl;
				
			}
			if(asum>n/2){
				long long zas=0,zbs=0;
				e.clear();
				for(long long i=1;i<=n;i++){
					if(a[i]<b[i]||a[i]<c[i]) continue;
					if(b[i]>c[i]){
						e.push_back(a[i]-b[i]);
					}else{
						e.push_back(a[i]-c[i]);
					}
				}
				sort(e.begin(),e.end());
				long long js=0;
				for(auto it:e){
					sum-=it;
					js++;
					if(js>=asum-n/2) break;
				}
				cout<<sum<<endl;
			}else if(bsum>n/2){
				long long zas=0,zbs=0;
				e.clear();
				for(long long i=1;i<=n;i++){
					if(b[i]<=a[i]||b[i]<c[i]) continue;
					if(a[i]>c[i]){
						e.push_back(b[i]-a[i]);
					}else{
						e.push_back(b[i]-c[i]);
					}
				}
				sort(e.begin(),e.end());
				long long js=0;
				for(auto it:e){
					sum-=it;
					js++;
					if(js>=bsum-n/2) break;
				}
				cout<<sum<<endl;
			}else if(csum>n/2){
				long long zas=0,zbs=0;
				e.clear();
				for(long long i=1;i<=n;i++){
					if(c[i]<=a[i]||c[i]<=b[i]) continue;
					if(a[i]>b[i]){
						e.push_back(c[i]-a[i]);
						//cout<<"ad"<<c[i]-a[i]<<endl; 
					}else{
						e.push_back(c[i]-b[i]);
						//cout<<"ad"<<c[i]-b[i]<<endl; 
					}
					
				}
				sort(e.begin(),e.end());
				long long js=0;
				for(auto it:e){
					sum-=it;
					js++;
					if(js>=csum-n/2) break;
				}
				cout<<sum<<endl;
			}else{
				cout<<sum<<endl;
			}
		}
		
	}
	return 0;
}
