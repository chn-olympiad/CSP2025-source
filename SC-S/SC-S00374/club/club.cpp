#include<bits/stdc++.h>
using namespace std;
int a[100005][3];
int d[100005][3];
int cha[100005];
int t;
void deal(){
	int n0=0,n1=0,n2=0;
	int ans=0;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
			d[n0][0]=i;
			n0++;
			ans+=a[i][0];
		}else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
			d[n1][1]=i;
			n1++;
			ans+=a[i][1];
		}else {
			d[n2][2]=i;
			n2++;
			ans+=a[i][2];
		}
	}
	if(n0>n/2){
		for(int i=0;i<n0;i++){
			cha[i]=min(a[d[i][0]][0]-a[d[i][0]][1],a[d[i][0]][0]-a[d[i][0]][2]);
		}
		sort(cha,cha+n0);
		int j=0;
		while(n0>n/2){
			n0--;
			ans-=cha[j];
			j++;
		}
	}
	if(n1>n/2){
		for(int i=0;i<n1;i++){
			cha[i]=min(a[d[i][1]][1]-a[d[i][1]][0],a[d[i][1]][1]-a[d[i][1]][2]);
		}
		sort(cha,cha+n1);
		int j=0;
		while(n1>n/2){
			n1--;
			ans-=cha[j];
			j++;
		}
	}
	if(n2>n/2){
		for(int i=0;i<n2;i++){
			cha[i]=min(a[d[i][2]][2]-a[d[i][2]][1],a[d[i][2]][2]-a[d[i][2]][0]);
		}
		sort(cha,cha+n2);
		int j=0;
		while(n2>n/2){
			n2--;
			ans-=cha[j];
			j++;
		}
	}
	cout<<ans<<endl;
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		deal();
	}
	return 0;
} 