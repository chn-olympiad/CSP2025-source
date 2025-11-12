#include<bits/stdc++.h>
using namespace std;
long long ans,n,m,people_l[509];
long long oc_0,oc_1;
void ki1(long long now,long long nowno,long long nowyes,long long now1,long long now0){
//	cout<<now1<<" "<<now0<<endl;
	if(now==n){
		if(nowyes>=m){
			ans++;
			ans%=998224353;
			return;
		}else{
		//	cout<<"wqeqwe"<<endl;
			return;
		}
	}else{
		if(now1!=0){
			ki1(now+1,nowno+1,nowyes,now1-1,now0);
		}
		if(now0!=0){
		//	cout<<"sb "<<people_l[now]<<" "<<nowno<<endl;
			if(people_l[now]<=nowno){
				ki1(now+1,nowno+1,nowyes,now1,now0-1);
				return;
			}else{
				if(nowyes+1>=m){
					cout<<now<<" "<<n<<" ";
					long long temp=n-now-1,temp1=1;
					for(long long i=1;i<=temp;i++){
						temp1*=temp;
					}	
					cout<<temp<<" "<<temp1<<" "<<endl;
					if(temp1>0)ans+=temp1;
				//	ans++;
					ans%=998224353;
					return;
				}else{
					ki1(now+1,nowno,nowyes+1,now1,now0-1);
					return;
				}
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(long long j=0;j<n;j++){
		char temp;
		cin>>temp;
		if(temp=='0'){
			oc_1++;
		}else{
			oc_0++;
		}
	}
	for(long long j=0;j<n;j++){
		cin>>people_l[j];
	//	cout<<people_l[j]<<endl;
	}
	ki1(0,0,0,oc_1,oc_0);
	cout<<ans<<endl;
	return 0;
}
