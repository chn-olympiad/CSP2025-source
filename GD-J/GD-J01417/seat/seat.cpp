#include<iostream>
#include<algorithm>
#include<cstring> 
using namespace std;
int a[110],n,m,tmp,ans1,ans2,b[110];
bool cmp(const int&x,const int&y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	b[a[1]]=true;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(b[a[i]]){
			tmp=i;
			break;
		}
	}
	ans1=tmp/n;
	if(tmp%n!=0){
		ans1++;
		if(ans1%2==1)ans2=tmp%n;
		else ans2=n-tmp%n+1;
	}
	else{
		if(ans1%2==1)ans2=n;
		else ans2=1;
	}
	cout<<ans1<<' '<<ans2;
	return 0;
}
