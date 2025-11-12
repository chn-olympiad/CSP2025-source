#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("replace.in","t",stdin);
	//freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		if((n+m)%2==0){
			cout<<n<<endl;
		}else{
			cout<<0<<endl;
		}
	}
	return 0;
} 

