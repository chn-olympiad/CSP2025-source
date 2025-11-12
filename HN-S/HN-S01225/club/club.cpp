#include<bits/stdc++.h>
using namespace std;
struct BBB{
	int man1,man2,man3;
};
struct Club{
	int ren,man;
};
bool cmp1(BBB a,BBB b){
	return a.man1>b.man1;
}
bool cmp2(BBB a,BBB b){
	return a.man2>b.man2;
}
bool cmp3(BBB a,BBB b){
	return a.man3>b.man3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		BBB a[n];
		Club club[n]={0,0};
		for(int i=0;i<n;i++){
			cin>>a[i].man1>>a[i].man2>>a[i].man3;
		}
		sort(a,a+n,cmp1);
		for(int i=0;i<n/2;i++){
			if(a[i].man1>=a[i].man2&&a[i].man1>=a[i].man3){
				club[i].man+=a[i].man1;
			}
		}
		sort(a,a+n,cmp2);
		for(int i=0;i<n/2;i++){
			if(a[i].man2>=a[i].man1&&a[i].man2>=a[i].man3){
				club[i].man+=a[i].man2;
			}
		}
		sort(a,a+n,cmp3);
		for(int i=0;i<n/2;i++){
			if(a[i].man3>=a[i].man2&&a[i].man3>=a[i].man1){
				club[i].man+=a[i].man3;
			}
		}
		int sum=0;
		for(int i=0;i<n;i++){
			sum+=club[i].man;
		}
		cout<<sum;
	}
	
	return 0;
}
