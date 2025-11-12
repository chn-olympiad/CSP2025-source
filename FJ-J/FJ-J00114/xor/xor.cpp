#include<bits/stdc++.h>
using namespace std;
int n,k,i,ai;
string a[50001];
//int f(string x,string y){
//	for(i=1;i<=max(x)
//}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>ai;
		if(k==0&&ai==0){
			cout<<0;
			break;
		}
		while(ai>1){
			if(ai%2==0){
				a[i]='0'+a[i];
			}else{
				a[i]='1'+a[i];
			}
			ai=ai/2;
		}
		a[i]='1'+a[i];
	}
	//for()
	return 0;
}
