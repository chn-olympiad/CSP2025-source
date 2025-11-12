#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;cin>>n>>q;
	vector<vector<string> > A(n,vector<string>(2));
	for(int i=0;i<n;i++){
		cin>>A[i][0]>>A[i][1];
	}
	while(q--){
		string a,b,t1="",t2="",t3="",t4="",t5="",t6="";
		cin>>a>>b;
		int x,y,z,ans=0;
		int len = a.size();
		for(int i=-1;i<len;i++){
			if(i!=-1){
				t1+=a[i];t2+=b[i];
			}
			if(t1==t2){
//				cout<<t1<<' '<<t2<<'\n';
				x = t1.size();
				t3="";
				t4="";
				for(int j=len;i<j&&j>=0;j--){
					if(j!=len){
						t3+=a[j];t4+=b[j];
					}
					if(t3==t4){
//						cout<<t3<<' '<<t4<<'\n';
						z = t3.size();
						y = len-x-z;
						t5 = a.substr(x,y);
						t6 = b.substr(x,y);
//						cout<<t5<<' '<<t6<<'\n';
						for(int u=0;u<n;u++){
							if(t5==A[u][0] && t6==A[u][1]){
								ans++;
							}
						}
					}else break;
				}
			}else break;
		}
		cout<<ans<<'\n';
	}
	return 0;
}