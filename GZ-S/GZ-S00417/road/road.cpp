//GZ-S00417 华东师范大学附属贵阳学校 谭斯雨
#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,k,a[N],ans;
int main(){
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
    	int x,y;
    	cin>>x>>y;
    	cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n-1;i++){
		ans+=a[i];
	}
	if(k==0){
		cout<<ans;
		return 0;
	}
	else{
		for(int i=1;i<=k;i++){
			int x,y;
			cin>>x;
			for(int j=1;j<=n;j++){
				cin>>y;
				x+=y;
			}
			ans=min(x,ans);
		}
	}
	cout<<ans;
	return 0;
}//我不想写了啊，我不行了，下次我一定好好背模板（立flag中），谁能告诉我最短路怎么写！！？
