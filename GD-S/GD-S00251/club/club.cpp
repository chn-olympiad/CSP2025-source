#include<bits/stdc++.h>
using namespace std;
int A[1000010];
int cmp(int x,int y){
	return x>y;
}
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){	
		long long ans=0;
		int n;
		cin>>n;
		int flag=0;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			if(b!=0||c!=0){
				flag=1;
			}
			ans+=(max(max(a,b),c));
			A[i]=a;
		}
		if(!flag){
			ans=0;
			sort(A+1,A+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=A[i];
			}
			cout<<ans<<"\n";
		}
		else{
			cout<<ans;
		}
	}
	return 0;
} 
