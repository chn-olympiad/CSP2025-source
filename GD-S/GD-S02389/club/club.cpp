#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.ans","w",stdout);
	int t;
	cin>>t;
	int cnt[10010];
	for(int d=1;d<=t;d++){
		int n,a[100100];
		cin>>n;
		int m=n/2;
		int x=0,y=0,z=0;
		for(int j=1;j<=n;j++){
			for(int i=1;i<=3;i++){
				cin>>a[i];
			}if(a[1]>a[2]&&a[1]>a[3]&&x<m){
				x++;
				cnt[d]+=a[1];
			}if(a[2]>a[1]&&a[2]>a[3]&&y<m){
				y++;
				cnt[d]+=a[2];
			}if(a[3]>a[1]&&a[3]>a[2]&&z<m){
				z++;
				cnt[d]+=a[3];
			}
		}
	}
	for(int i=1;i<=t;i++){
		cout<<cnt[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

