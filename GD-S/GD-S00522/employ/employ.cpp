#include<iostream>
#include<string>
using namespace std;
int n,m,a[510],b[510],cnt,ans;
string s;
int main(){
	//freopen("employ.in ",r,stdin)
	//freopen("employ.out",w,stdout)
	cin>>n>>m;
	getline(cin,s);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) b[i]=i;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(s.j==1 && a[j]>=j){
			cnt++:
			}
		}
		if(cnt==m){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
