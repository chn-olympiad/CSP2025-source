#include <iostream>
#include <string>
using namespace std;
int ans,n,q;
string in3,in4,in1[10010],in2[10010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>in1[i]>>in2[i];
	}
	while(q--){
		ans=0;
		cin>>in3>>in4;
		for(int i=1;i<=n;i++){
			if(in3==in1[i]&&in4==in2[i]) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
