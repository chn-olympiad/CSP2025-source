#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("replace.in","r",stdin);
	//freopen("replace.out","w",stdout);
	string s1,s2,x,y,z,q1,q2;
	int n,q,ans[10000];
	cin>>n>>q;
	for(int i=0;i<n;i++){
    cin>>s1>>s2;	
}
    for(int i=0;i<q;i++){
    	cin>>q1>>q2;
	if(s1==q1&&s2==q2){
		ans[i]=2;
	}
	else ans[i]=0; 
}
	for(int i=0;i<q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
} 
