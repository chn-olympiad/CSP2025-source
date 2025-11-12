#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,x,a[500010],ans,k,flag;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1||a[i]<0){
			flag=1;
		}
	}
	if(flag==0){
		if(k==1){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					cnt++;
				}
			}
			cout<<cnt;
		}else if(k==0){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					cnt++;
				}
				if(a[i]==1&&a[i+1]==1){
					cnt++;
					i++;
				}
			}
			cout<<cnt;
		}else{
			cout<<"0";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		x=a[i];
		for(int j=i+1;j<=n+1;j++){
			if(x==k){
				ans++;
				i=j-1;
				break;
			}
			x^=a[j];
		}
	}
	cout<<ans;
	return 0;
}
//              A                      KKK             KKK
//             A A                     K K           K K
//            A A A                    K K         K K
//           A A A A                   K K       K K
//          A A   A A                  K K     K K
//         A A     A A                 K K   K K
//        A A       A A                K K K K
//       A A         A A               K K K
//      A AAAAAAAAAAAAA A              K K K K
//     A AAAAAAAAAAAAAAA A             K K   K K
//    A A               A A            K K     K K
//   A A                 A A           K K       K K
//  A A                   A A          K K         K K
// A A                     A A         K K           K K
//AAA                       AAA        KKK             KKK