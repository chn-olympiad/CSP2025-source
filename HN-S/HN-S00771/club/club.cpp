#include<bits/stdc++.h>
using namespace std;

struct cc{
	int c1,c2,c3,maxz;
};

bool c(cc a,cc b){
	return a.c1>b.c1;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//Ren5Jie4Di4Ling5%
	int t,n,p1=0,p2=0,p3=0,ans1=0,ans=0,f=true;
	cin>>t;
	while(t--){
		cin>>n;
		vector<cc> a(n);
		for(int i=0; i<n; i++){
			cin>>a[i].c1>>a[i].c2>>a[i].c3;
			if(a[i].c2!=0 || a[i].c3!=0){
				f=false;
			}
			a[i].maxz=max(a[i].c1,max(a[i].c2,a[i].c3));
		}
		
		if(f){
			ans1=0;
			sort(a.begin(),a.end(),c);
			for(int i=0; i<n/2; i++){
				ans1+=a[i].c1;
			}
			cout<<ans1<<endl;
			continue;
		}
		
		for(int i=0; i<n; i++){
			if(a[i].c1==a[i].maxz){
				ans+=a[i].c1;
			}
			if(a[i].c2==a[i].maxz){
				ans+=a[i].c2;
			}
			if(a[i].c3==a[i].maxz){
				ans+=a[i].c3;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
