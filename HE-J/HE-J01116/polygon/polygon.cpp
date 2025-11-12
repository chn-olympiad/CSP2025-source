#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans=0;;
const int mod=998244353;
bool f1=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;//T4 is too difficult for me
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f1=0;
	}sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}//12pts
	//Robin i love u
	//AFO 
	return 0;
}
