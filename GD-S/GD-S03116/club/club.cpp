#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100010][4],ans,cnt1,cnt2,cnt3;
priority_queue<long long> q,q2,q3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=cnt1=cnt2=cnt3=0;
		while(!q.empty())q.pop();
		while(!q2.empty())q2.pop();
		while(!q3.empty())q3.pop();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
				cnt1++;
				ans+=a[i][1];
				q.push(max(a[i][2],a[i][3])-a[i][1]);
			}
			else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
				cnt2++;
				ans+=a[i][2];
				q2.push(max(a[i][1],a[i][3])-a[i][2]);
			}
			else{
				cnt3++;
				ans+=a[i][3];
				q3.push(max(a[i][1],a[i][2])-a[i][3]);
			}
		}
		while(cnt1>n/2){
			ans+=q.top();
			q.pop();
			cnt1--;
		}
		while(cnt2>n/2){
			ans+=q2.top();
			q2.pop();
			cnt2--;
		}
		while(cnt3>n/2){
			ans+=q3.top();
			q3.pop();
			cnt3--;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
