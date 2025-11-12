#include<bits/stdc++.h>
using namespace std;
int ts[10];
const int N=1e5;
int ans[N];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	
	for(int i=1;i<=t;i++){
		int  n;
		cin>>n;
		int s=n/2;
		
		ans[i]=0;
		for(int j=1;j<=n;j++){
			int a,b,c;
			cin>>a>>b>>c;
			int a1,b1,c1;
			int ans1;
			if(a1<=s&&b1<=s&&c1<=s){
				int l=max(a,b);
				ans1=max(l,c);
				ans[i]+=ans1;
				if(ans1==a)a1++;continue;
				if(ans1==b)b1++;continue;
				if(ans1==c)c1++;continue;
				
			}else if(a1<=s&&b1<=s&&c1>s){
				ans1=max(a,b);
				ans[i]+=ans1;
				if(ans1==a)a1++;continue;
				if(ans1==b)b1++;continue;
			}else if(a1<=s&&b1>s&&c1<=s){
				ans1=max(a,c);
				ans[i]+=ans1;
				if(ans1==a)a1++;continue;
				if(ans1==c)c1++;continue;
			}else if(a1>s&&b1<=s&&c1>s){
				ans1=max(c,b);
				ans[i]+=ans1;
				if(ans1==c)c1++;continue;
				if(ans1==b)b1++;continue;
			}else if(a1<=s&&b1>s&&c1>s){
				ans1=a;
				ans[i]+=ans1;
				a1++;
				continue;
				
			}else if(a1>s&&b1<=s&&c1>s){
				ans1=b;
				ans[i]+=ans1;
				b1++;
				continue;	
			}else if(a1>s&&b1>s&&c1<=s){
				ans1=c;
				ans[i]+=ans1;
				c1++;
				continue;	
			}
			
		}
	}
	for(int i=1;i<=t;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}


