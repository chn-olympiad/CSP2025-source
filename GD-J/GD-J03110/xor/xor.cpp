#include <bits/stdc++.h>
using namespace std;
int a[500005];unsigned int c;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,z;cin>>n>>z;int ans=0;int w=0;bool f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];c=0;f=0;
		if(a[i]==z){ans++;w=i;continue;
		}for(int j=w+1;i>1&&j<=i;j++){
			f=0;c=0;
			for(int k=j;k<=i;k++){
				c^=a[k];if(c==z){
					ans++;c=0;f=1;w=k;break;
				}
			}if(f)break;
		}
	}cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
