#include<bits/stdc++.h>
using namespace std;
bool q[1005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	int n;
	int a[1005][3];
	cin>>t;
	while(t--){
		cin>>n;
		if(n==2){
			int cnt1=0;
			while(n>0){
				cin>>a[n][0]>>a[n][1]>>a[n][2];
				n--;
			}
			cnt1=max(max(a[1][0]+a[2][1],a[1][0]+a[2][2]),max(max(a[1][1]+a[2][0],a[1][1]+a[2][2]),max(a[1][2]+a[2][0],a[1][2]+a[2][1])));
			cout<<cnt1<<endl;
			continue;
		}
		int f=0,x=0,b=0;
		int f1=0,x1=0,b1=0;
		bool q[1005];
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if((!q[i])&&max(a[i][0],max(a[i][1],a[i][2]))==a[i][0]&&f1<=n/2){
				f+=a[i][0];
				f1++;
			}
			else if((!q[i])&&max(a[i][0],max(a[i][1],a[i][2]))==a[i][1]&&x1<=n/2){
				x+=a[i][1];
				x1++;
			}
			else if((!q[i])&&max(a[i][0],max(a[i][1],a[i][2]))==a[i][2]&&b1<=n/2){
				b+=a[i][2];
				b1++;
			}
			q[i]=1;
		}
		int cnt=f+x+b;
		cout<<cnt<<endl;
	}
	return 0;
}
