#include<bits/stdc++.h>
using namespace std;
int a[1000001][3],k[1000001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,x=0,y=0,z=0,ans=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(max(a[i][0],max(a[i][1],a[i][2]))==a[i][0])x++;
			else if(max(a[i][0],max(a[i][1],a[i][2]))==a[i][1])y++;
			else z++;
		}
		for(int i=0;i<n;i++){
			ans+=max(a[i][0],max(a[i][1],a[i][2]));
		}
		if(x>n/2){
			for(int i=0;i<n;i++){
				if(max(a[i][0],max(a[i][1],a[i][2]))==a[i][0]){
					k[i]=a[i][0]-max(a[i][1],a[i][2]);
				}
				else k[i]=0;
			}
			sort(k,k+n);
			for(int i=0;i<n/2;i++){
				ans-=k[i];
			}
			cout<<ans<<endl;
		}
		else if(y>n/2){
			for(int i=0;i<n;i++){
				if(max(a[i][0],max(a[i][1],a[i][2]))==a[i][1]){
					k[i]=a[i][1]-max(a[i][0],a[i][2]);
				}
				else k[i]=0;
			}
			sort(k,k+n);
			for(int i=0;i<n/2;i++){
				ans-=k[i];
			}
			cout<<ans<<endl;	
		}
		else if(z>n/2){
			for(int i=0;i<n;i++){
				if(max(a[i][0],max(a[i][1],a[i][2]))==a[i][2]){
					k[i]=a[i][2]-max(a[i][1],a[i][0]);
				}
				else k[i]=0;
			}
			sort(k,k+n);
			for(int i=0;i<n/2;i++){
				ans-=k[i];
			}
			cout<<ans<<endl;
		}
		else{
			cout<<ans<<endl;
		}
	}
}
