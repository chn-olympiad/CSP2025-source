#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
typedef long long ll;
int t,n;
struct node{
	int a1,a2,a3,num;
}a[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		int ans1=0,ans2=0,ans3=0,cnt=0;
		for(int i=1;i<=n;i++){
			cnt=0;
			cnt=max(cnt,max(a[i].a1,max(a[i].a2,a[i].a3)));
			ans1+=cnt;
		}
		cout<<ans1<<endl;
	}
	return 0;
}

