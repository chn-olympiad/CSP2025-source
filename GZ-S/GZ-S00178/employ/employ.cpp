//GZ-S00178 贵阳市华师一学校 张金畅
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[510];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m>>s;
	int x;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[x]++;
	}
	int cnt=0,d=1;
	for(int i=1;i<=n;i++){
		if(a[i]<=d){
			d=d-a[i]+1;
			cnt+=a[i];
		}else{
			d=0;
			cnt+=a[i]-d;
		}
	}
	cout<<cnt<<" "<<d;
	return 0;
}
