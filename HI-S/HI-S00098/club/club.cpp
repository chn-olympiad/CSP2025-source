#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T;
int n;
struct club{
	int c1,c2,c3;
}a[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>T;
	while(T--){
		int ans=0;
		int cl1,cl2,cl3;
		cin>>n;
		int jx=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].c1>>a[i].c2>>a[i].c3;
		}
		for(int i=1;i<=n;i++){
			if(a[i].c1>a[i].c2&&a[i].c1>a[i].c3){
			cl1++;
			ans+=a[i].c1; 
			}	
			if(a[i].c2>a[i].c1&&a[i].c2>a[i].c3){
				cl2++;
				ans+=a[i].c2; 
			}		
			if(a[i].c3>a[i].c1&&a[i].c3>a[i].c2) {
				cl3++;
				ans+=a[i].c3;
			}
		}
		if(cl1<jx&&cl2<jx&&cl3<jx){
			 cout<<ans<<endl;
		}
	}
	return 0;
}
