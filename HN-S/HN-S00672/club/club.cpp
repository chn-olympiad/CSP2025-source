#include<bits/stdc++.h>
using namespace std;
int n,C1,C2,C3,ans;
struct node{
	int c1,c2,c3;
}a[100050];
void yzc(int x,int sum){
	if(C1>n/2||C2>n/2||C3>n/2){
		return ;
	}
	if(x-1==n){
		ans=max(ans,sum);
		return ;
	}
	C1++;
	yzc(x+1,sum+a[x].c1);
	C1--;
	C2++;
	yzc(x+1,sum+a[x].c2);
	C2--;
	C3++;
	yzc(x+1,sum+a[x].c3);
	C3--;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		n=0,C1=0,C2=0,C3=0,ans=0;
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].c1>>a[i].c2>>a[i].c3;
		}
		yzc(1,0);
		cout<<ans<<endl;
	}
	return 0;
}  
