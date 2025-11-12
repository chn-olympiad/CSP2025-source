#include<bits/stdc++.h>
using namespace std;
int t,n,gz[4],jd[10050];
long long ans;
struct cl{
	int my;
	int bm;
}a[4][10050];
int po(cl x,cl y){
	return x.my>y.my;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;++i){
			for(int j=0;j<3;++j){
				cin>>a[i][j].my;
				if(j==0){
					a[i][j].bm=1;
				}
				else if(j==1){
					a[i][j].bm=2;
				}
				else{
					a[i][j].bm=3;
				}
			}
		}
		for(int i=0;i<n;++i){
			sort(a,a+n,po);
			ans+=a[i][0].my;
			gz[a[i][0].bm]++;
		}
		for(int i=0;i<n;++i){
			if(gz[i]>=n/2){
				jd[i]=a[i][0].my-a[i][1].my;
			}
		}
		for(int i=0;i<n;++i){
			sort(jd,jd+3);
			for(int j=0;j<gz[i]-n/2;++j){
				ans-=jd[i];
				gz[i]--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
