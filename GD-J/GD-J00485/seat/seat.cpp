#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
int n,m;
int a[maxn];
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int tmp=a[1];
	sort(a+1,a+n*m+1,cmp);
	int num=lower_bound(a+1,a+1+n*m,tmp)-a;
	num=n*m-num+1;
//	cout<<num<<endl;
	int flag=1,now=1;
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(flag==1){
			while(now<=n){
				cnt++;
				if(cnt==num){
					cout<<i<<' '<<now;
					return 0;
				}
				now+=flag;
			}
		}
		else{
			while(now>1){
				now+=flag;
				cnt++;
				if(cnt==num){
					cout<<i<<' '<<now;
					return 0;
				}
			}
		}
		flag*=-1;
	}
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
