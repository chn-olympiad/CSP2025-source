#include<bits/stdc++.h>
using namespace std;
long long ans,sum,T,n,a[5][100005],su[5];
long long ss(int k){
	if(k==n+1){
		ans=max(ans,sum);
		return 0;
	}else if(k==n){
		long long s=0;
		for(int i=1;i<=3;i++){
			if(su[i]==n/2){
				continue;
			}
			s=max(s,a[i][k]);
		}
		sum+=s;
		ss(k+1);
		sum-=s;
	}else{
		for(int i=1;i<=3;i++){
			if(su[i]==n/2){
				continue;
			}
			su[i]++;
			sum+=a[i][k];
			ss(k+1);
			sum-=a[i][k];
			su[i]--;
		}
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		sum=0;
		su[1]=0;
		su[2]=0;
		su[3]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[j][i];
			}
		}
		ss(1);
		cout<<ans<<endl;
	}
	return 0;
}
