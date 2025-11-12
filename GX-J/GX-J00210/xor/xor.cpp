#include<bits/stdc++.h>
using namespace std;
struct str{
	int a1 ;
	bool b1 = 0 ;
};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout) ;
	int n ;
	int k ;
	cin >> n >> k ;
	str a1[n] ; 
	for(int i = 0 ;i<n;i++){
		cin >> a1[i].a1 ;
	}
	int all = 0 ;
	//for(int i = 0 ;i<n;i++){
	//	if(a1[i].a1==k){
	//		
	//	}
	//}
	for(int i = 0;i<n;i++){
		int b1 = a1[i].a1 ;
		int i1 = i+1 ;
		if(b1==k){
			all = all+1 ;
			a1[i].b1 = 1 ;
		}else{
			while(a1[i1].b1==0&&i1<n){
				if(a1[i1].a1==k){
					all = all+1 ;
					a1[i1].b1 = 1 ;
					i = i1 ;
					break;
				}
				b1 = b1^a1[i1].a1 ;
				i1 = i1+1 ;
				if(b1==k){
					for(int j = i ;j<=i1;j++){
						a1[i].b1 = 1 ;
					}
					i = i1 ;
					all = all+1 ;
					break;
				}
			}
		}
	}
	cout << all ;
	return 0 ;
}
