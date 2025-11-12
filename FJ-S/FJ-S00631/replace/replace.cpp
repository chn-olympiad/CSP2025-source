#include<bits/stdc++.h>
using namespace std;
int n,q;
const int N=2e5+5;
struct zf{
	string a1;
	string a2;
};
zf re[N],pro[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>re[i].a1>>re[i].a2;
	}
	for(int i=1;i<=q;i++){
		cin>>pro[i].a1>>pro[i].a2;
	}
	for(int i=1;i<=q;i++){
		int ans=0;
			for(int j=1;j<n;j++){
			if(pro[i].a1==re[j].a1){
				if(pro[i].a2==re[j].a2){
				ans=2;	
				}
				else{
					
				}
			}
			else{
				
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
