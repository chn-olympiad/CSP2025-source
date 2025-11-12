#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110],x;
bool cmp(int bj1,int bj2){
	return bj1>bj2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>x;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(x>a[i]){
			x=i;
			break;
		}
	}
	cout<<x/n+(x%n!=0)<<" ";
	if(((x-1)/n)%2==0){
		if(x%n==0){
			cout<<n;
			return 0;
		}
		cout<<x%n;
	}else{
		if(x%n==0){
			cout<<1;
			return 0;
		}
		cout<<n-x%n+1;
	}
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