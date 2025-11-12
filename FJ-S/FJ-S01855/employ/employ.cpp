#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],ch[505],k[505];
bool l[505];
long long sum=0;
string a;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(m>n){
		cout<<"0"<<endl;
		return 0;
	}
	sort(c+1,c+n+1);
	for(int i=0;i<a.size();i++){
		ch[i+1]=ch[i]+a[i]-'0';
	}
	if(ch[n]<c[1]){
		for(int i=1;i<=n;i++){
			sum*=i;
			sum%=998244353;
		}
	} else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(ch[j]>=c[i]){
					k[i]=j-1;
					break;
				}
			}
		}
		for(int i=1;i<=n;i++){
			sum*=k[i];
			sum%=998244353;
		}
	}
	cout<<sum<<endl;
	return 0;
}
