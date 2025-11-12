#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m;
struct node{
	int id,sc;
}a[N];
bool cmp(node x,node y){
	return x.sc>y.sc;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i].sc);
		a[i].id=i;
	}
	bool fl=false;
	sort(a+1,a+1+n*m,cmp);
	int ans1=0,ans2=0;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			ans1=i/n,ans2=i%n;
			if(i%n==0){
				ans1=i/n,ans2=n,fl=1;
			}
		}
	}
	if(fl){
		cout<<ans1<<' '<<ans2<<endl;
		return 0;
	}	
	if(ans1%2==0){
		ans2=ans2,ans1++;
	}else{
		ans2=(n-ans2)+1,ans1++;
	}
	cout<<ans1<<' '<<ans2;
	return 0;
}
