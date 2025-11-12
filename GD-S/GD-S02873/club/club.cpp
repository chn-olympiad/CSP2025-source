#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct people{
	int d1,d2,d3;
	int mx;
}a[100005];
void sort_people(int d){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(d==1){
				if(a[i].d1<a[i+1].d1)
					swap(a[i],a[i+1]);
			}if(d==2){
				if(a[i].d2<a[i+1].d2)
					swap(a[i],a[i+1]);
			}if(d==3){
				if(a[i].d3<a[i+1].d3)
					swap(a[i],a[i+1]);
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int d[4],ans=0;
		memset(d,0,4);
		cin>>n;
		int Max_People=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
		}
		cout<<ans<<'\n'; 
	}
	return 0;
} 
