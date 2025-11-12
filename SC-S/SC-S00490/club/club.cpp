#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct Node{
	int dx,bh,dx2,bh2;
} a[N];
int n,t,a1,a2,a3,cnt[5],ans;
bool cmp(Node x,Node y){
	return (x.dx-x.dx2)>(y.dx-y.dx2);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1>>a2>>a3;
			if(a1==min(min(a1,a2),a3)){
				if(a2>a3){
					a[i]={a2,2,a3,3};
				}
				else {
					a[i]={a3,3,a2,2};
				}
			}
			else if(a2==min(min(a1,a2),a3)){
				if(a1>a3){
					a[i]={a1,1,a3,3};
				}
				else {
					a[i]={a3,3,a1,1};
				}
			}
			else if(a3==min(min(a1,a2),a3)){
				if(a1>a2){
					a[i]={a1,1,a2,2};
				}
				else {
					a[i]={a2,2,a1,1};
				}
			}
		}
        sort(a+1,a+1+n,cmp);
//      for(int i=1;i<=n;i++){
//			cout<<a[i].dx<<" "<<a[i].bh<<" "<<a[i].dx2<<" "<<a[i].bh2<<"\n";
//		}
//		cout<<"\n";
        for(int i=1;i<=n;i++){
        	if(cnt[a[i].bh]<n/2){
        		ans+=a[i].dx;
        		cnt[a[i].bh]++;
			}
			else {
				ans+=a[i].dx2;
				cnt[a[i].bh2]++;
			}
		}
		cout<<ans<<"\n";
		memset(cnt,0,sizeof(cnt));
	}
	return 0;
}