#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int sum=0;
		int cnt1=0,cnt2=0,cnt3=0;
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			int a1,a2,a3;
			cin>>a1>>a2>>a3;
			if(cnt1<=n/2){
				if(cnt2<=n/2){
					if(cnt3<=n/2){
						sum+=max(a1,max(a2,a3));
						if(max(a1,max(a2,a3))==a1) cnt1++;
						if(max(a1,max(a2,a3))==a2) cnt2++;
						if(max(a1,max(a2,a3))==a3) cnt3++;
					}else{
						sum+=max(a1,a2);
						if(max(a1,a2)==a1) cnt1++;
						if(max(a1,a2)==a2) cnt2++;
					}
				}else if(cnt2>n/2 && cnt3<=n/2){
					sum+=max(a1,a3);
					if(max(a1,a3)==a1) cnt1++;
					if(max(a1,a3)==a3) cnt3++;
				}
			}else if(cnt1>n/2 && cnt3<=n/2 && cnt2<=n/2){
				sum+=max(a3,a2);
				if(max(a3,a2)==a3) cnt3++;
				if(max(a3,a2)==a2) cnt2++;
			}
			if(cnt1<=n/2 && cnt2>n/2 && cnt3>n/2){
				sum+=a1;
				cnt1++;
			}else if(cnt1>n/2 && cnt2<=n/2 && cnt3>n/2){
				sum+=a2;
				cnt2++;
			}else if(cnt1>n/2 && cnt2>n/2 && cnt3<=n/2){
				sum+=a3;
				cnt3++;
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
