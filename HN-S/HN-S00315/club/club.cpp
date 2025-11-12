#include <bits/stdc++.h>
using namespace std;
int t,n,a[100005][5];
/*struct node{
	int a,b,c;
	bool flag;
}a[100005];
/*bool cmp1(node a,node b){
	return a.a>b.a;
}
bool cmp2(node a,node b){
	return a.b>b.b;
}
bool cmp3(node a,node b){
	return a.c>b.c;
}*/
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		if(n==2){
			int a1=a[1][1],a2=a[1][2],a3=a[1][3],b1=a[2][1],b2=a[2][2],b3=a[2][3];
			sort(a[1]+1,a[1]+4,cmp);
			sort(a[2]+1,a[2]+4,cmp);
			if((a[1][1]==a1&&a[2][1]==b1)||(a[1][1]==a2&&a[2][1]==b2)||(a[1][1]==a3&&a[2][1]==b3)){
				if(a[1][1]>a[2][1]){
					cout<<a[1][1]+a[2][2];
				}else if(a[1][1]<a[2][1]){
					cout<<a[1][2]+a[2][1];
				}else{
					cout<<a[1][1]+max(a[1][2],a[2][2]);
				}
			}else{
				cout<<a[1][1]+a[2][1];
			}
		}
		int x=0,y=0,ans=0;
		for(int i=1;i<=n;i++){
			if(a[i][1]>a[i][2]&&x<=n/2){
				x++;
				ans+=a[i][1];
			}
			else if(a[i][2]>a[i][1]&&y<=n/2){
				y++;
				ans+=a[i][2];
			}
		}
		cout<<ans;
	}
} 
