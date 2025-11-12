//GZ-S00447 贵阳市第二十一中学 郭灏轩 
#include<bits/stdc++.h>
using namespace std;
int a[200005][5];
int mx[200005];
int t[200005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;cin>>n;
		int n2=n/2;
		bool f=1;
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				mx[i]=max(a[i][j],mx[i]);
				t[mx[i]]++;
			}
			if(a[i][2]!=0 && a[i][3]!=0) f=0;
			sum+=a[i][1];
		}
		if(n==2){
			cout<<max(a[1][1]+a[2][2],max(a[1][1]+a[2][3],max(a[1][2]+a[2][1],max(a[1][2]+a[2][3],max(a[1][3]+a[2][1],a[1][3]+a[2][2])))));
		}
		if(f){
			for(int i=1; ;i++){
				if(n2==0){
					cout<<sum;
					break;
				}
				if(t[i]){
					for(int j=1;j<=t[i];j++){
						if(n2){
							sum-=i;
							n2--;
						}
					}
				}
			}
		}
	}
	return 0;
}
