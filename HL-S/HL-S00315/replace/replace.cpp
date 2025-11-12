#include<bits/stdc++.h>

using namespace std;
int n,q;
const int N=2e5+10;
string s[N][3];
int ans[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int j=1;j<=q;j++){
		string t1,t2;
		cin>>t1>>t2;
		int l=t1.length();
		for(int k=0;k<l;k++){
			for(int i=k;i<l;i++){
				bool flag=0;
				for(int p=0;p<=k;p++){
					if(t1[p]!=t2[p]){
						flag=1;
					}
				}
				if(flag==0){
					for(int p=i;p<l;p++){
						if(t1[p]!=t2[p]){
							flag=1;
						}
					}
					if(flag==0){
						for(int w=1;w<=n;w++){
							for(int p=k;p<=i;p++){
								if(t1[p]!=s[w][1][p]||t2[p]!=s[w][2][p]){
									flag=1;
									break;
								}
							}
							if(flag==0){
								ans[j]++;
							}
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}

