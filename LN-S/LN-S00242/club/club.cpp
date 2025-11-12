//Ren5Jie4Di4Ling5%
#include<bits/stdc++.h>
using namespace std;
int main(void){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	for(int i=0;i<t;i++){
		int n,a[n],ans=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b>>c;
		}sort(a,a+n);
		for(int i=0;i<n*2;i++)ans+=a[i];
		cout<<ans<<endl;
	}return 0;
}
/*
				}sort(s,s+n,stp);
		for(int j=0;j<n;j++){
			
		}*/
