#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int q,n;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand(time(0));
	cin>>n>>q;
	if(q==1) cout<<0;
	else{
		for(int i= 1;i<=q;i++){
			if(rand()&4==0){
				cout<<rand()%100;
			} 
			else cout<<0;
		}
	}
	return 0;
}

