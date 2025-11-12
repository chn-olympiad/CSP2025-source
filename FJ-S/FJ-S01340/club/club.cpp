#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t;
int main(){
	freopen("club","r",stdin);
	freopen("club","w",stdout);
	cin>>t;
	while(t--){
		int n,a1,a2,a3,b[N][4],s1=0,s2=0,s3=0,ans=0;
		cin>>n;
		int half=n/2;
		for(int i=1;i<=n;i++){
			cin>>a1>>a2>>a3;
			if(a1>a2 and a1>a3 and s1<half){
				ans+=a1;
				s1++;
				continue;
			}
			else if(a2>a1 and a2>a3 and s2<half){
				ans+=a2;
				s2++;continue;
			}
			else if(a3>a2 and a3>a1 and s3<half){
				ans+=a3;
				s3++;continue;
			}
			else if(a3==a2 and a3>a1){
				if(s3<s2 and s3<half) s3++;
				else if(s2<half) s2++;
				ans+=a3;continue;
			}
			else if(a3==a2 and a3<a1 and s1<half){
				s1++;
				ans+=a1;continue;
			}
			else if(a3==a1 and a3>a2){
				if(s3<s1 and s3<half) s3++;
				else if(s1<half) s1++;
				ans+=a3;continue;
			}
			else if(a3==a1 and a3<a2 and s2<half){
				s2++;
				ans+=a2;continue;
			}
			else if(a1==a2 and a1>a3){
				if(s1<s2 and s1<half) s1++;
				else if(s2<half) s2++;
				ans+=a1;continue;
			}
			else if(a1==a2 and a1<a3 and s3<half){
				s3++;
				ans+=a3;continue;
			}
			else {
				int l=max(a1,a2);
				ans+=max(l,a3);continue;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
