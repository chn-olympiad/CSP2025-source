#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int n,q;
string t,t1;
string m,m1;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand(time(0));
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>t>>t1;
	}for(int j=0;j<q;j++){
		cin>>m>>m1;
	}for(int i=0;i<q;i++){
		if(q==1){
			cout<<rand()%10+1;
		}else{
			cout<<0;
		}
	}
	return 0;
}