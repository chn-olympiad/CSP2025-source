#include<bits/stdc++.h>
using namespace std;
int n,s,a[500010],cnt;
struct qu{
	int start;
	int lengh;
};
qu q[500010];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.ans","w",stdout);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int o=0;
			for(int k=i;k<=j;k++){
				o=o|a[k];
				if(o==s)cnt++;
			}
		}
	}		
	cout<<cnt;																																																									
}
