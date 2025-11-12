#include<bits/stdc++.h>
using namespace std;
int n,a[5005],s;
int pd(int a1,int ax,int a3){
	if((a1+ax+a3)>max(a1,max(ax,a3))*2) return true;
	else return false;
}
int cs(int n1,int iii){
	int xxx=1,ssx=1;
	if(n1/2<iii){
		iii=n1-iii;
	}for(int i=1;i<=iii;i++){
		ssx*=i;
		xxx=xxx*(n1-i+1);
	}return xxx/ssx;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}if(n==3){
		if(pd(a[1],a[2],a[3])==true){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	for(int i=3;i<=n;i++){
		s+=cs(n,i);
		s%=998244353;
	}cout<<s;
	return 0;
}
