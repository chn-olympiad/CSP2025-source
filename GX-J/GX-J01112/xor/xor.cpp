#include <bits/stdc++.h>
using namespace std;
int n=0,p=0,a[5000],b[5000];
int main(){   
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>p;
	for(int i=1;i<=n;i++){cin>>a[i];
	}cout<<(1&1)<<'\n';
	if(n==1){if(a[1]!=0)cout<<0;
		else cout<<1;
		}else if(n==2){if(a[1]==0&&a[2]==0){cout<<2;
			}else if((a[1] & a[2])==0){cout<<1;
			}else cout<<0;
		       }else cout<<0;
	return 0;
}


