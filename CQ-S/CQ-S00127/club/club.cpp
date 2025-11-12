#include<bits/stdc++.h>
using namespace std;
int arr[100005];
int brr[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==2){
			int a,b,c,d,e,f;
			cin>>a>>b>>c>>d>>e>>f;
			int t1=max(a,max(b,c));
			int t2=max(d,max(e,f));
			if(a==t1&&d==t2){
				int t3=a-max(b,c);
				int t4=d-max(e,f);
				cout<<a+d-min(t3,t4)<<endl;
			}else if(b==t1&&e==t2){
				int t3=a-max(a,c);
				int t4=d-max(d,f);
				cout<<b+e-min(t3,t4)<<endl;
			}else if(c==t1&&f==t2){
				int t3=c-max(a,b);
				int t4=f-max(d,e);
				cout<<c+f-min(t3,t4)<<endl;
			}else{
				cout<<t1+t2<<endl;
			}
		}else{
			int ans=0;
			bool flag=true;
			bool tr=true;
			int ao=0,bo=0;
			for(int i=1;i<=n;i++){
				int a,b,c;
				cin>>a>>b>>c;
				arr[i]=a;
				brr[i]=b;
				if(b!=0&&c!=0) flag=false;
				if(c!=0) tr=false;
				ans+=max(a,max(b,c));
			}
			if(!flag){
				cout<<ans<<endl;
			}else{
				if(flag){
					sort(arr+1,arr+n+1);
					int sum=0;
					for(int i=n;i>=n-n/2+1;i--){
						sum+=arr[i];
					}
					cout<<sum<<endl;
				}
			}
			
		}
	}
	return 0;
}
