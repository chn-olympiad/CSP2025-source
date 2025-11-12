#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll a[100005][3];
ll b[100005],b_sum;
ll ans;
ll club_1_sum,club_2_sum,club_3_sum;

bool cmp(int c,int d){
	return c>d;
}

void Manyidu(){
	
	club_1_sum=0,club_2_sum=0,club_3_sum=0;
	ans=0;
	
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	
	bool flag=1;
	for(ll i=1;i<=n;i++){
		if(a[i][2]!=0 || a[i][3]!=0)flag=0;
	}
	if( flag == 1 ){
		for(ll i=1;i<=n;i++)b[++b_sum]=a[i][1];
		sort(b+1,b+b_sum+1,cmp);
		for(ll i=1;i<=n/2;i++)ans+=b[i];
		cout<<ans<<endl;
		return;
	}
	
	
	for(int i=1;i<=n;i++){
		if(a[1]>=a[2] && a[2]>=a[3] ){
			if(club_1_sum >= n/2){
				if(club_2_sum>=n/2){
					ans+=a[i][3],club_3_sum++;
				}else ans+=a[i][2],club_2_sum++;
			}else ans+=a[i][1],club_1_sum++;
		}
		else if(a[1]>=a[3] && a[3]>=a[2] ){
			if(club_1_sum >= n/2){
				if(club_3_sum>=n/2){
					ans+=a[i][2],club_2_sum++;
				}else ans+=a[i][3],club_3_sum++;
			}else ans+=a[i][1],club_1_sum++;
		}
		else if(a[2]>=a[1] && a[1]>=a[3] ){
			if(club_2_sum >= n/2){
				if(club_1_sum>=n/2){
					ans+=a[i][3],club_3_sum++; 
				}else ans+=a[i][1],club_1_sum++;
			}else ans+=a[i][2],club_2_sum++;
		}
		else if(a[2]>=a[3] && a[3]>=a[1] ){
			if(club_2_sum >= n/2){
				if(club_3_sum>=n/2){
					ans+=a[i][1],club_1_sum++;
				}else ans+=a[i][3],club_3_sum++;
			}else ans+=a[i][2],club_2_sum++;
		}
		else if(a[3]>=a[1] && a[1]>=a[2] ){
			if(club_3_sum >= n/2){
				if(club_1_sum>=n/2){
					ans+=a[i][2],club_2_sum++;
				}else ans+=a[i][1],club_1_sum++;
			}else ans+=a[i][3],club_3_sum++;
		}
		else if(a[3]>=a[2] && a[2]>=a[1] ){
			if(club_3_sum >= n/2){
				if(club_2_sum>=n/2){
					ans+=a[i][1],club_1_sum++;
				}else ans+=a[i][2],club_2_sum++;
			}else ans+=a[i][3],club_3_sum++;
		}
	}
	cout<<ans<<endl;
}


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	
	while(t--){
		Manyidu();
	}
	
	return 0;
	
}
