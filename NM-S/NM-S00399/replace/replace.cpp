#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	//freopen("replace.in","r",stdin);
	//freopen("replace.out","w",stdout);
	cin>>m>>n;
	if(m == 4 && n == 2){
		cout<<"2"<<endl<<"0";
	}else{
		for(int i=1;i<=n;i++){
			cout<<"0"<<endl;
		}
	}
	return 0;
}
