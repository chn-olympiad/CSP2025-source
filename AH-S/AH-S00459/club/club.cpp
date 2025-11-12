#include<bits/stdc++.h>
using namespace std;
int a[100005][3]={0},aa[100005]={0},bb[100005]={0},cc[100005]={0};
int main(){
  	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,as=0;
		cin>>n;
		int x=0,y=0,z=0;
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>=a[i][1] && a[i][0]>=a[i][2]){
				as+=a[i][0];
				aa[x]=min(a[i][0]-a[i][1],a[i][0]-a[i][2]);
				x++;
				continue;
			}
			if(a[i][1]>=a[i][0] && a[i][1]>=a[i][2]){
				as+=a[i][1];
				bb[y]=min(a[i][1]-a[i][0],a[i][1]-a[i][2]);
				y++;
				continue;
			}
			if(a[i][2]>=a[i][1] && a[i][2]>=a[i][0]){
				as+=a[i][2];
				cc[z]=min(a[i][2]-a[i][0],a[i][2]-a[i][1]);
				z++;
				continue;
			}
		}
		if(x>n/2){
			int c=x-n/2;
			sort(aa,aa+x);
			for(int i=0;i<c;i++){
				as-=aa[i];
			}
			cout<<as<<endl;
			continue;
		}
		if(y>n/2){
			int c=y-n/2;
			sort(bb,bb+y);
			for(int i=0;i<c;i++){
				as-=bb[i];
			}
			cout<<as<<endl;
			continue;
		}
		if(z>n/2){
			int c=z-n/2;
			sort(cc,cc+z);
			for(int i=0;i<c;i++){
				as-=cc[i];
			}
			cout<<as<<endl;
			continue;
		}
		cout<<as<<endl;
	}
	return 0;
}
