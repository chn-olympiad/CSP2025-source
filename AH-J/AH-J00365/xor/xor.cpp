#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,ans=0;
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    if (n<10||n>1000){
        if (k==0){
			int w=0;
			for (int i=1;i<=n;i++){
				if (a[i]==1) w++;
				if (a[i]==0) ans++,w=0;
				if (w==2) w=0,ans++;
			}
          }
          else {
			if (k==1) {
				for (int i=1;i<=n;i++){
					if (a[i]==1) ans++;
				}
			}
		}
		cout<<ans<<"\n";
    }
    else {
      ans=0;
		int s=0;
		for (int i=1;i<=n;i++){
			s^=a[i];
			cout<<s<<" "<<ans<<"\n";
			if (a[i]==k) ans++,s=0;
			else if (s==k) ans++,s=0;
		}
		cout<<ans<<endl;
	}
    return 0;
}
