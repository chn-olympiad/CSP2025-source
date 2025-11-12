#include<bits/stdc++.h>
using namespace std;
int t,n,x,y,z,Zo,club;
struct stu{
	int cnt1;
	int cnt2;
	int cnt3;
	int max;
	int ans;
};
stu a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		n=0,x=0,y=0,z=0,Zo=0,club=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].cnt1>>a[i].cnt2>>a[i].cnt3;
		}
		for(int i=1;i<=n;i++){
			if(a[i].cnt1>=a[i].cnt2){
				a[i].max=1;
				a[i].ans=a[i].cnt1;
			}else{
				a[i].max=2;
				a[i].ans=a[i].cnt2;
			}
			if(a[i].cnt3>=a[i].ans){
				a[i].max=3;
				a[i].ans=a[i].cnt3;
			}
			if(a[i].max==1){
				x++;
			}
			if(a[i].max==2){
				y++;
			}
			if(a[i].max==3){
				z++;
			}
			club+=a[i].ans;
		}
		Zo=(x+y+z)/2;
		cout<<club<<endl;
	}
	return 0;
}
