#include<bits/stdc++.h>
using namespace std;
int t;
bool cz(int x,int y){
	return x>y;
}
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,a[114514],ans=0,ffc,fcc;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i]>>ffc>>fcc;
		}
		sort(a,a+n,cz);
		for(int i=0;i<n/2;i++){
			ans+=a[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
I want to find my code on HNÃÔ»óÐÐÎª´óÉÍ pls! 
*/
