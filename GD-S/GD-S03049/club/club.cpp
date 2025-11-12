#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int n,a[N][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		int maxn=-1;long long s=0;int b[4];
		memset(b,0,sizeof(b));
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=0;j<2;j++){
				cin>>a[i][j];
				if(b[j]<n/2){
					if(maxn<=a[i][j]) {maxn=a[i][j];}
				}
			}
			for(int j=0;j<2;j++){
				if(maxn==a[i][j]) {b[j]++;break;}
			}
			s+=maxn;maxn=-1;
		}
		cout<<s<<endl;
	}
	return 0;
}//这啥编译器啊，报错给英文完全看不懂，写的dp只能改成贪心 
