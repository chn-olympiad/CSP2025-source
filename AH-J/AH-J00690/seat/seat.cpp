#include<bits/stdc++.h>
using namespace std;
int n,m,xx;//行，列
int a[1005];
bool cmp(int l,int r){
	return l>r;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	xx=a[1];
	int x=0,y=0;
	sort(a+1,a+1+n*m,cmp);//www.KFCv.com/:me50$
//	for(int i=1;i<=n*m;i++)cout<<a[i]<<" ";
//	cout<<endl;
	for(int i=1;i<=n*m;i++){
//		cout<<i<<" a:"<<a[i]<<" x"<<xx<<endl;
		if(a[i]==xx){
			int num=i/n;
			int nu2=i%n;
			if(nu2==0){
				printf("%d %d",i/n,n);
			}else{
				y=1+num;
				if(y%2==0){
					x=n+1-nu2;
				}else{
					x=nu2;
				}
				printf("%d %d",y,x);
			}
			return 0;
		}
	}
	return 0;
}
