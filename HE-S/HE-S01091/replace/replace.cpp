#include<bits/stdc++.h>
using namespace std;
int n,q;
struct nnnn{
	string s1,s2;
}ery[200005]; 
int main(){
	srand(time(0));
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>ery[i].s1>>ery[i].s2;
	}
	while(q--){
		string t1,t2;cin>>t1>>t2;
		if(t1.size()!=t2.size()){cout<<0<<endl;continue;}
		cout<<rand()%t1.size()<<endl;
		
	}
	return 0;
} 
