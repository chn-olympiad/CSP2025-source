#include<bits/stdc++.h>
using namespace std;
long long n,q,sum;
string t[3],s[200005][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>t[1]>>t[2];
		for(int k=0;k<t[1].size();k++){
			for(int j=1;j<=n;j++){
					sum+=(s[j][1].size()^t[1].size());
			}
		}
		sum=sum-(sum>t[2].size())*t[2].size();
		cout<<sum%(abs(n-q)==1?n+q:abs(n-q))%n<<endl;
	}
	return 0;
}
