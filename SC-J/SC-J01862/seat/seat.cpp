#include<bits/stdc++.h>
using namespace std;
int n,m;//n行 m列 
int a[105];
bool f=1;
struct S{
int zw,zwi,zwj;
}x[105];
bool pyh(int s1,int s2){
return s1>s2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int sum=a[1];
	sort(a+1,a+n*m+1,pyh);
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i]<<endl;
//	}
	int l=0,mn=n,h=1,s=0;
	for(int i=1;i<=n*m;i++){
		if(s%m==0&&s!=0){
			h++;
//			cout<<1<<endl;
		}
		if(f){
			l++;
			x[i].zw=a[i];
			x[i].zwi=h;
			x[i].zwj=l;
			if(l==mn){
				f=!f;
				l++;
			}
		}else{
			l--;
			x[i].zw=a[i];
			x[i].zwi=h;
			x[i].zwj=l;
			if(l==1){
				f=!f;
				l--;
			}
		}
		if(x[i].zw==sum){
		cout<<x[i].zwi<<" "<<x[i].zwj;
		break;
		}
//	cout<<x[i].zw<<" "<<x[i].zwi<<" "<<x[i].zwj<<" ";
	s++;
	}
	return 0;
}