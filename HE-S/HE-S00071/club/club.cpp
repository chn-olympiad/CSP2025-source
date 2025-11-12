#include <bits/stdc++.h>
using namespace std;
int t;
int cnt1,cnt2,cnt3;
int a[100005][4];
int maxx[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(maxx,0,sizeof(maxx));
		int n;
		int sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			maxx[i]=max(max(a[i][1],a[i][2]),a[i][3]);
			if(a[i][1]>max(a[i][2],a[i][3])){
				cnt1++;
			}else if(a[i][2]>max(a[i][1],a[i][3])){
				cnt2++;
			}else if(a[i][3]>max(a[i][1],a[i][2])){
				cnt3++;
			}
		}
		if(cnt1<=(n/2) && cnt2<=(n/2) && cnt3<=(n/2)){
			for(int i=1;i<=n;i++){
				sum+=maxx[i];
			}
		}else{
			sum=maxx[n];
		}
		cout<<sum<<endl;
	}
    return 0;
}
