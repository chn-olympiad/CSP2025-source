#include<iostream>
using namespace std;
struct s{
	string i1,i2;
}s0[200002],t[200002];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s0[i].i1>>s0[i].i2;
	}
	for(int i=1;i<=q;i++){
		int p=0;
		cin>>t[i].i1>>t[i].i2;
		for(int j=1;j<=n;j++){
			if(s0[i].i1==t[i].i1&&s0[i].i2==t[i].i2){
				p=1;
			}
		}
		if(p==1){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
