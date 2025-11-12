#include <bits/stdc++.h> 
using namespace std;
const int N=100005;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		int a1[N];
		int a2[N];
		int a3[N];
		int cnt1=1,cnt2=1,cnt3=1;
		cin>>n;
		bool f1=0,f2=0,f3=0;
		long long sum=0;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		sort(a1+1,a1+1+n,greater<int>());
		sort(a2+1,a2+1+n,greater<int>());
		sort(a3+1,a3+1+n,greater<int>());
		for(int i=1;i<=n;i++){
			if(cnt1-1>=n/2&&!f1){
				f1=1;
			}
			if(cnt2-1>=n/2&&!f2){
				f2=1;
			}
			if(cnt3-1>=n/2&&!f3){
				f3=1;
			}
			if(f1==1){
				int q=max(a2[cnt2],a3[cnt3]);
				if(q==a2[cnt2]){
					cnt2++;
				}else{
					cnt3++;
				}
				sum+=q;
			}else if(f2==1){
				int q=max(a1[cnt1],a3[cnt3]);
				if(q==a1[cnt1]){
					cnt1++;
				}else{
					cnt3++;
				}
				sum+=q;
			}else if(f3==1){
				int q=max(a1[cnt1],a2[cnt2]);
				if(q==a1[cnt1]){
					cnt1++;
				}else{
					cnt2++;
				}
				sum+=q;
			}else{
				int q=max(a1[cnt1],max(a2[cnt2],a3[cnt3]));
				if(q==a1[cnt1]){
					cnt1++;
				}else if(q==a2[cnt2]){
					cnt2++;
				}else{
					cnt3++;
				}
				sum+=q;
			}
			//cout<<sum<<endl;
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 4 4 2 1 3 2 4 5 3 4 3 5 1 4 0 1 0 0 1 0 0 2 0 0 2 0 2 10 9 8 4 0 0
4 0 1 0 0 1 0 0 2 0 0 2 0
*/
