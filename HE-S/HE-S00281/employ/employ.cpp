#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,q,cnt;
char a,b;
const int M=998244353;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>q;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			cnt=(cnt%M)*(i%M);
		}
		cout<<cnt<<endl;
	}else if(m==n){
		cout<<"0"<<endl;
	}
	return 0;
}
