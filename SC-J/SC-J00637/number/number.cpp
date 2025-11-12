#include<bits/stdc++.h>
using namespace std;
string s;
long long a[20]; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
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