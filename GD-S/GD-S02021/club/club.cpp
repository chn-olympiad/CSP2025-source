#include <bits/stdc++.h>
using namespace std;
struct node{
	int sum;
	int id;
};
int n,A1[100005],A2[100005],A3[100005],cnt1,cnt2,cnt3;
long long ans[100005];
node BM1[100005],BM2[100005],BM3[100005];
bool cmp(node x,node y){
	return x.sum>y.sum;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
    	cin>>n;
    	cnt1=0,cnt2=0,cnt3=0;
    	long long anss=0;
    	for(int i=1;i<=n;i++){
    		cin>>A1[i]>>A2[i]>>A3[i];
    		if(A1[i]>=A2[i]&&A1[i]>=A3[i]){
    			ans[i]=A1[i];
    			BM1[++cnt1].sum=A1[i]-max(A2[i],A3[i]);
    			BM1[cnt1].id=i;
			}
			if(A2[i]>=A1[i]&&A2[i]>=A3[i]){
				ans[i]=A2[i];
    			BM2[++cnt2].sum=A2[i]-max(A1[i],A3[i]);
    			BM2[cnt2].id=i;
			}
			if(A3[i]>=A2[i]&&A3[i]>=A1[i]){
				ans[i]=A3[i];
    			BM3[++cnt3].sum=A3[i]-max(A1[i],A2[i]);
    			BM3[cnt3].id=i;
		   }
		}
		if(cnt1>n/2){
			sort(BM1+1,BM1+cnt1+1,cmp);
			for(int i=n/2+1;i<=cnt1;i++){
				if(A2[BM1[i].id]>A3[BM1[i].id]){
					ans[BM1[i].id]=A2[BM1[i].id];
				}
				else ans[BM1[i].id]=A3[BM1[i].id];
			}
		}
		if(cnt2>n/2){
			sort(BM2+1,BM2+cnt2+1,cmp);
			for(int i=n/2+1;i<=cnt2;i++){
				if(A1[BM2[i].id]>A3[BM2[i].id]){
					ans[BM2[i].id]=A1[BM2[i].id];
				}
				else ans[BM2[i].id]=A3[BM2[i].id];
			}
		}
		if(cnt3>n/2){
			sort(BM3+1,BM3+cnt3+1,cmp);
			for(int i=n/2+1;i<=cnt3;i++){
				if(A2[BM3[i].id]>A1[BM3[i].id]){
					ans[BM3[i].id]=A2[BM3[i].id];
				}
				else ans[BM3[i].id]=A1[BM3[i].id];
			}

		}
		for(int i=1;i<=n;i++){
			anss+=ans[i];
		}
		cout<<anss<<endl;
	}
	return 0;
}
