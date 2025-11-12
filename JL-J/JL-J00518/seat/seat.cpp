#include<bits/stdc++.h>
using namespace std;
struct f{
	int seat,score;
}a[110];
bool cmp(f x,f y){
	return x.score>y.score;
}int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].score;
		a[i].seat=i;
	}sort(a+1,a+n*m+1,cmp);
	int x1=1,y1=1,sum=1,k=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[sum].seat==1){
				cout<<x1<<' '<<y1<<endl;
				return 0;
			}if(sum%m==0)x1++,k=0;
			else if(sum%m==1){
				if(y1==1)k=1;
				else if(y1==m)k=-1;
			}y1+=k,sum++;
		}
	}
	return 0;
}
