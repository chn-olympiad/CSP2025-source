//gitxiaozheng
//rp++!
#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int a[maxn];
bool cmp(int a,int b){
	return a>b;
}
bool flag11=true,flag22=true;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,xiaoR=0,weizhi=1,hang,lie1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xiaoR=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==xiaoR){
			weizhi=i;
			break;
		}
	}
	hang=ceil((double)weizhi/(double)n);
	cout<<hang<<' ';
	if(hang%2==1){
		lie1=weizhi%n;
		if(lie1==0){
			lie1=n;
		}
	}else{
		lie1=n-(weizhi%n-1);
		if(weizhi%n==0){
			lie1=1;
		}
	}
	cout<<lie1;
	return 0;
}
