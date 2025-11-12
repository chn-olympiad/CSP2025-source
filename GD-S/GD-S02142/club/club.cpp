#include <bits/stdc++.h>
using namespace std;
int a[5][100005],r[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int k=0;k<t;k++){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[0][i]>>a[1][i]>>a[2][i];
		}
		int ans=0;
		for(int i=0;i<n;i++){
			if(a[0][i]==max(a[1][i],max(a[2][i],a[0][i]))){
				if(r[0]>n/2){
					a[0][i]=0;
				}else{
					r[0]++;
					ans+=a[0][i];
				}
			}else if(a[1][i]==max(a[1][i],max(a[2][i],a[0][i]))){
				if(r[1]>n/2){
					a[1][i]=0;
				}else{
					r[1]++;
					ans+=a[1][i];
				}
			}else if(a[2][i]==max(a[1][i],max(a[2][i],a[0][i]))){
				if(r[2]>n/2){
					a[2][i]=0;
				}else{
					r[2]++;
					ans+=a[2][i];
				}
		    }
		}
		cout<<ans;
	}
	return 0;
}
