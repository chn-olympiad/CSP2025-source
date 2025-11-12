#include<bits/stdc++.h>
using namespace std;
const int long long N=1e5;
long long t,n,cnt;
long long aa[5][5],m;
long long a[N+5],b[N+5],c[N+5];
long long bm[5]; //表示第i个部门的人数 
bool cy[N+5];  //表示第i个成员是否进入部门 
bool check(int x){ //检查部门人数是否小于一半 
	if (bm[x]>n/2)
		return 0;
	return 1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >>t;
	while (t--){
		cin >>n;
		for (int i=1;i<=n;i++){
			cin >>a[i]>>b[i]>>c[i];
		}
		sort (a+1,a+n+1);
		for (int i=n;i>n/2;i--){
			cnt+=a[i];
		}
		cout <<cnt<<endl;
		cnt=0;
	}
	return 0;
}
