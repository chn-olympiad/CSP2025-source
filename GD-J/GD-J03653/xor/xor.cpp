#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e5*5+500;
int n,k,ans=0,ttt=0;
int a[N];
int ttttttt(int i){
	for(int q=1;q<=n-i;q++){
		for(int j=i;j<=n;j++){
			int temp=0;
			for(int e=j;e<=n&&e<=q+j;e++){
				temp^=a[e];
				if(temp==k){
					return e+1;
				}
			}
		}
	}
	return -1;
}
void dfs(int step,int as){
	//cout<<step<<" "<<as<<endl;
	if(step>n){
		ans=max(as,ans);
		return;
	}
	for(int j=step;j<=n;j++){
		int temp=0;
		for(int e=j;e<=n;e++){
			temp^=a[e];
			if(temp==k){
				dfs(e+1,as+1);
			}
		}
	}
	return ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		//a[i]=1;
	}
	if(n<32){
		for(int j=1;j<=n;j++){
			int temp=0;
			for(int e=j;e<=n;e++){
				temp^=a[e];
				if(temp==k){
					dfs(e+1,1);
				}
			}
		}
		cout<<ans;
	}
	else{
		int i=1,ans2=0;
		while(i<=n){
			i=ttttttt(i);
			if(i==-1){
				break;
			}
			ans2++;
		}
		cout<<ans2<<endl;
	}
	return 0;
}
