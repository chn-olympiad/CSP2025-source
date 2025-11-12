#include<bits/stdc++.h> 
using namespace std;
#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[100006],t;
long long ans,sum,dis,yyy=0;
long long qq[100005],as=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
	cin>>n;
	yyy=0;
	for(int i=1;i<=n;i++){
		
		cin>>a[1]>>a[2]>>a[3];
		if(a[1]>a[2]&&a[1]>a[3]){
			ans++;
			yyy+=a[1];
			qq[i]=a[1];
		}else if(a[2]>a[1]&&a[2]>a[3]){
			sum++;
			yyy+=a[2];
			qq[i]=a[2];
		}else if(a[3]>a[2]&&a[3]>a[1]){
			dis++;
			yyy+=a[3];
			qq[i]=a[3];
		}if(n/2<yyy){
			as=qq[1];
			for(int i=2;i<=n;i++){
				if(as>qq[i]){
					as=qq[i];
				}
			}yyy=yyy-as;
		}
	}cout<<yyy<<endl;
	}
	return 0;
}
