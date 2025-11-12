#include <bits/stdc++.h>
using namespace std;
int a[5005]={0};
int n,m,k,l;
int ans=0;
void QAQ(int a[],int now,int ovo,int sum,int qwq){
	if(now>n){
		return ;
	}
	if(sum+a[now]>a[now]*2 && qwq>=3){
		ans++;
	}
	ans%=998244353;
	QAQ(a,now+1,1,sum,qwq+1);
	QAQ(a,now+1,0,sum,qwq);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
//函数写死了
	cout<<ans;
	return 0;
} 