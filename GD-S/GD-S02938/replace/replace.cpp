#include<bits/stdc++.h>
using namespace std;
const int N=200005;
string s[N][2],w[N][2],ans[N]={0};
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>w[i][1]>>w[i][2];
	}
	bool f2,f1;
	for(int i=1;i<=q;i++){
		int t=0;
		for(int j=1;j<=n;j++){
			for(int z=0;z*2<sizeof(w[i][1]);z++){
				f2=true;
				f1=true;
				for(int a=z+1;a<=sizeof(w[i][1]);a++){
					if(s[j][1][a-z]!=w[i][1][a])f2=false;
				}
				if(f2){
					string b=w[i][1];
					for(int a=z+1;a<=sizeof(w[i][1]);a++){
						b[a]=s[j][2][a-z];
					}
					for(int a=1;a<=sizeof(b);a++){
						if(b[a]!=w[i][2][a]){
							f1=false;
						}
					}
					if(f1)t++;
				}
			}
		}
		ans[i]=t;
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<endl;
	} 
	return 0;
}
