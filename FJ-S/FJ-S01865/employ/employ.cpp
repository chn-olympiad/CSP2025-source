#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
constexpr int MOD=998244353;
int n,m;
int s[510],c[510];
int st[20];
bool chk(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i]&&c[st[i]]>i-cnt-1)cnt++;
	}
	return cnt>=m;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	char x;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x=='1')s[i]=1;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=10){//expect 8pts
		int res=0;
		for(int i=1;i<=n;i++)st[i]=i;
		do{
			if(chk()){
				res++;
//				for(int i=1;i<=n;i++)cout<<st[i];
//				cout<<endl;
			}
		}while(next_permutation(st+1,st+n+1));
		cout<<res;
	}
}
