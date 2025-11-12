#include<bits/stdc++.h>
using namespace std;
long long int ans;
int n,a[5001];
bool visit[5001]={false},v[5001]={false};
void s(int y,int sum,int ma){
	if(y<0) return;
	if(y==0){
		if(sum>ma*2&&(!v[sum])){
			ans+=1;
			v[sum]=true;
			//cout<<b<<" "<<y<<" "<<sum<<" "<<ma<<endl;
			return;
		}
	}
	for(int i=0;i<n;i++){
		if(!visit[i]){
			visit[i]=true;
			s(y-1,sum+a[i],max(a[i],ma));
			visit[i]=false;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	sort(a,a+n);
    for(int i=3;i<=n;i++){
    	s(i,0,0);
    	for(int i=0;i<n;i++) v[i]=false;
	}
	cout<<ans;
	return 0;
}
