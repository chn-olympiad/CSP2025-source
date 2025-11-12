#include<bits/stdc++.h>
using namespace std;
int t;
struct f{
	int x,y,z;
}a[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int k=0,n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			k+=max(a[i].x,max(a[i].y,a[i].z));
		}
		cout<<k<<endl;
	} 
	return 0; 
} 
