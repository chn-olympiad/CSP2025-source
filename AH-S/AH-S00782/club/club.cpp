#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],cnt[3],sum[10];
int main(){
	freopen("club.cpp","r",stdin);
	freopen("club.cpp","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=3;i++){
		cnt[i]=0;
	}
	for(int i=1;i<=t;i++){//输入
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
	}
	for(int k=1;k<=t;k++){
		for(int i=1;i<=n;i++){//分配
			int max=-1;
			if(a[i]>=max && cnt[1]<=n/2){
				max=a[i];
				cnt[1]++;
			}
			if(b[i]>=max && cnt[2]<=n/2){
				max=b[i];
				cnt[1]--;
				cnt[2]++;
			}
			if(c[i]>=max && cnt[3]<=n/2){
				max=c[i];
				cnt[2]--;
				cnt[3]++;
			}
			sum[t]+=max;
		}
	}
	for(int k=1;k<=t;k++){
		for(int i=1;i<=n;i++){//分配
			int max=-1;
			if(a[i]>=max && cnt[1]<=n/2){
				max=a[i];
				cnt[1]++;
			}
			if(b[i]>=max && cnt[2]<=n/2){
				max=b[i];
				cnt[1]--;
				cnt[2]++;
			}
			if(c[i]>=max && cnt[3]<=n/2){
				max=c[i];
				cnt[2]--;
				cnt[3]++;
			}
			sum[t]+=max;
		}
	}
	for(int i=1;i<=t;i++){//输出
		cout<<sum[i]<<endl;
	}
	return 0;
}
