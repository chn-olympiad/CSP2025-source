#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
//注意：N大小   long long   freopen   程序名   文件夹名
//T3 :30
int n,_;string a[N],b[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>_;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	string t1,t2;
	while(_--){
		int ans=0;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			string k=t1;
			int x=k.find(a[i]);
			if(k==a[i]&&b[i]==t2)ans++;
			else if(x<=k.size()+7){
				string sb=k.substr(0,x);
				sb+=b[i];
				sb+=k.substr(x+a[i].size(),(k.size()-a[i].size()));
				if(sb==t2)ans++;
				//cout<<sb<<" "<<t2<<" "<<ans<<"\n";	
			}
			
		}
		cout<<ans<<"\n";
	}

	return 0;
}
/* 0_o*/

