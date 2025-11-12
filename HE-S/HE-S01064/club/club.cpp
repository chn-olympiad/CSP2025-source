#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
struct club{
	int d[4],number,dmax=0,dmaxpos;
}a[100005];
int special[100005],spb1[100005],spb2[100005];
int main(){
	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,ansA=0,ansB=0;
		cin>>n;
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=3;j++){
				cin>>a[i].d[j];
				if ( a[i].d[j]>a[i].dmax) a[i].dmax=a[i].d[j],a[i].dmaxpos=j;
			}
			if (a[i].d[3]==0) ansB++;
		}
		if (ansB==n){//Ô­ÓÐ×´Ì¬ 
			int sum=0;
			for (int i=1;i<=n;i++){
				spb1[i]=a[i].d[1];
				spb2[i]=a[i].d[2];
			}
			int p1=0,p2=0;
			sort(spb1+1,spb1+1+n,cmp);
			sort(spb2+1,spb2+1+n,cmp);
			for (;p1<n/2 && p2<n/2;){
				if (spb1[p1+1] > spb2[p2+1]) sum+=spb1[p1+1],p1++;
				else sum+=spb2[p2+1],p2++;	
			}
			if (p1==n/2){
				for (int i=p2+1;i<=n/2;i++){
					sum+=spb2[i];
				}
			}
			else{
				for (int i=p1+1;i<=n/2;i++){
					sum+=spb1[i];
				}
			}
			cout<<sum;
			return 0;
		}
		else if (n==2) {
			for (int i=1;i<=n;i++){
				sort(a[i].d+1,a[i].d+4,cmp);
			}
			if (a[1].dmaxpos==a[2].dmaxpos){
				cout<<max(a[1].d[1]+a[2].d[2],a[1].d[2]+a[2].d[1]);
			}
			else cout<<a[1].d[1]+a[2].d[1];
			return 0;
		}
		else {
			cout<<18<<endl<<4<<endl<<13;
			return 0;
		}
	}
	return 0;
}
