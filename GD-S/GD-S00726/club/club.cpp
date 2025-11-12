#include<bits/stdc++.h>
using namespace std;
#define int long long 
int a[100005],b[100005],c[100005],tw[100005];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q1,q2,q3;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _;
	cin>>_;
	while(_--){
		int n,sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			int tmp[5];
			tmp[1]=a[i],tmp[2]=b[i],tmp[3]=c[i];
			sort(tmp+1,tmp+4,greater<>());
			tw[i]=tmp[1]-tmp[2];
		}
//		for(int i=1;i<=n;i++)cout<<tw[i]<<" ";
//		cout<<'\n';
		for(int i=1;i<=n;i++){
			if(a[i]>=b[i]&&a[i]>=c[i]){
				if((int)q1.size()<n/2){
					q1.push({tw[i],i});
				}else{
					int o=q1.top().first,oo=q1.top().second;
					if(tw[i]>o){
						q1.pop();
						q1.push({tw[i],i});
						sum+=a[oo]-o;
					}else{
						sum+=a[i]-tw[i];
					}
				}
			}else if(b[i]>=c[i]&&b[i]>=a[i]){
				if((int)q2.size()<n/2){
					q2.push({tw[i],i});
				}else{
					int o=q2.top().first,oo=q2.top().second;
					if(tw[i]>o){
						q2.pop();
						q2.push({tw[i],i});
						sum+=b[oo]-o;
					}else{
						sum+=b[i]-tw[i];
					}
				}
			}else{
				if((int)q3.size()<n/2){
					q3.push({tw[i],i});
				}else{
					int o=q3.top().first,oo=q3.top().second;
					if(tw[i]>o){
						q3.pop();
						q3.push({tw[i],i});
						sum+=c[oo]-o;
					}else{
						sum+=c[i]-tw[i];
					}
				}
			}
		}
		while(!q1.empty()){
			int t=q1.top().second;
			sum+=a[t];
			q1.pop();
		}
		while(!q2.empty()){
			int t=q2.top().second;
			sum+=b[t];
			q2.pop();
		}
		while(!q3.empty()){
			int t=q3.top().second;
			sum+=c[t];
			q3.pop();
		}
		cout<<sum<<'\n';
	}
	return 0;
}
