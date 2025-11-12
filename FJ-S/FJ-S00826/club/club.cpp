#include<bits/stdc++.h>
using namespace std;
int t,n[100000+10],a_1[20000+10],a_2[20000+10],a_3[20000+10],cnt1,cnt2,cnt3,maxn[20000+10],maxn1[20000+10],maxn2[20000+10],maxn3[20000+10];
long long sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cnt1=0;
		cnt2=0;
		cnt3=0;
		cin>>n[i];
		for(int j=1;j<=n[i];j++){
			maxn[j]=0;
			maxn1[j]=0;
			maxn2[j]=0;
			maxn3[j]=0;
			cin>>a_1[j]>>a_2[j]>>a_3[j];
			maxn[j]=max(a_1[j],max(a_2[j],a_3[j]));
		if(maxn[j]==a_1[j]){
				maxn1[j]=maxn[j];
				cnt1++;
			}
			if(maxn[j]==a_2[j]){
				maxn2[j]=maxn[j];
				cnt2++;
			}
			if(maxn[j]==a_3[j]){
				maxn3[j]=maxn[j];
				cnt3++;
			}
			sum+=maxn[j];
		}
		sort(maxn1+1,maxn1+n[i]+1);
		sort(maxn2+1,maxn2+n[i]+1);
		sort(maxn3+1,maxn3+n[i]+1);
		if(cnt1>n[i]/2){
			for(int j=1;j<=cnt1-n[i]/2;j++){
				sum-=maxn1[j];
			}
		}
		if(cnt2>n[i]/2){
			for(int j=1;j<=cnt2-n[i]/2;j++){
				sum-=maxn2[j];
			}
		}
		if(cnt3>n[i]/2){
			for(int j=1;j<=cnt3-n[i]/2;j++){
				sum-=maxn3[j];
			}
		}
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
}
