#include<bits/stdc++.h>
using namespace std;
int a[5005];
int ans=0;
int cnt=3;
int n;
void cz(int my_ans,int jc,int cnt,int maxn,int x){
	if(jc==cnt){
		if(my_ans>maxn*2){
//			cout<<my_ans<<" "<<maxn<<endl;
			ans++;
		}
		return ;
	}
	else if(jc<cnt) {
		for(int i=x;i<=n;i++){
			cz(my_ans+a[i],++jc,cnt,a[i],++x);
		}
	}
}
int main(){
	freopen("polygon2.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(cnt<=n){
//		cout<<cnt<<endl;
		cz(0,0,cnt,0,1);
		cnt++;
//		cout<<ans<<endl<<endl;
	}
	cout<<ans%998, 244, 353;
	return 0;
//	5 1 2 3 4 5
//	5 2 2 3 8 10
} 
