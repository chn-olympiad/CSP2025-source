#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int s;
	cin>>s;
	for(int i=0;i<s;i++){
		int ans=0;
		int t;
		cin>>t;
		int a[t],b[t],c[t];
		for(int i=0;i<t;i++){
			cin>>a[i]>>b[i]>>c[i];
		}

		int BM1=0,BM2=0,BM3=0;
		int op=t/2;
		int y=max(a[i],b[i]);
		int x=max(y,c[i]);
		for(int i=0;i<t;i++){
			if(x==a[i]&&BM1<=op){
				ans+=x;
				BM1++;
			}else if(x==b[i]&&BM2<=op){
				ans+=x;
				BM2++;
			}else if(x==c[i]&&BM3<=op){
				ans+=x;
				BM3++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


