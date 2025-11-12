#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],b[N];
int n,k;
bool flg(int xx,int yy){
	int ans=a[xx];
	xx++;
	for(int i=xx;i<=xx+yy-1;i++){
		if(!b[i]){
			ans^=a[xx];
		}else{
			return false;
		}
	}
	if(ans==k){
		return true;
	}else{
		return false;
	}
}
void app(int xx,int yy){
	for(int i=xx;i<=xx+yy;i++){
		b[i]=1;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=(n-i+1);j++){
			if(flg(j,i)){
				app(j,i);
			}
		}
	}
	bool flag=true;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(flag && b[i]){
			flag=false;
			ans++;
		}else{
			flag=true;
		}
	}
	printf("%d\n",ans);
	return 0;
}
