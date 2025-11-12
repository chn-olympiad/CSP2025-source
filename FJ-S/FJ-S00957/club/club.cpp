#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a[100002][5],s[10];
	cin>>t;
	for(int p=1;p<=t;p++){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
			    cin>>a[i][j];
			}
		}
		if(n==2){
			s[p]=max(a[1][1]+a[2][2],max(a[1][1]+a[2][3],max(a[1][2]+a[2][1],max(a[1][2]+a[2][3],max(a[1][3]+a[2][1],a[1][3]+a[2][2])))));
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(a[j][1]<a[j-1][1]){
						swap(a[j][1],a[j-1][1]);
					}
				}
			}
			for(int i=n;i>=n/2;i--){
				s[p]+=a[i][1];
			}
		}
	}
	for(int p=1;p<=t;p++){
		cout<<s[p]<<endl;
	}
	return 0;
}
