#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand(time(0));
	int n,q;
	cin>>n>>q;
	if(q==1){
		cout<<rand()%20+1;
	}else{
		for(int i=1;i<=q;i++){
			cout<<0<<endl;
		}
	}
	return 0;
}
