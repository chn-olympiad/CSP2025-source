#include<bits/stdc++.h>
using namespace std;
struct sss{
	int x;
	int t;
	int p;
}a[100010];
bool cmp(sss A,sss B){
	if(A.t==B.t)return A.x>B.x;
	return A.t<B.t;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		int n,sum = 0,ans = 0;
		cin>>n;
		int s = n/2,cnt = 1;
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=3;j++){
				cin>>a[cnt].x;
				a[cnt].t = j;
				a[cnt].p = i;
//				cout<<a[i].x<<" "<<a[i].t<<endl;
				cnt++;
			}
		}
		cnt--;
		sort(a+1,a+cnt+1,cmp);
		for(int i = 1;i<=cnt;i++){
			cout<<a[i].x<<" "<<a[i].t<<endl;
		}
		if(a[n+1].x==0&&a[n*2+1].x==0){
			for(int i = 1;i<=s;i++){
				sum+=a[i].x;
			}
			cout<<sum;
			break;
		}else if(a[n*1+1].x!=0&&a[n*2+1].x==0){
			int arr = 1,brr = n+1;
			while(ans<=s*2){
				if(a[arr].x>=a[brr].x){
					sum+=a[arr].x;
					arr++;
				}else{
					sum+=a[brr].x;
					brr++;
				}
				ans++;
				cout<<sum;
				break;
			}
		}
	}
	return 0;
}

