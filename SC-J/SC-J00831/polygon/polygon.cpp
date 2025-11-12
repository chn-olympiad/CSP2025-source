#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
bool cmt(int x,int y){
	return x<y;
}
int res;
void f(int tot,int maxx,int h,int num){
	if(tot>maxx*2&&num>=3){
		res++;
		//cout<<tot<<" "<<maxx<<" "<<h<<" "<<num<<endl;
		res%=998;
		res%=224;
		res%=353; 
	}
	for(int i=h+1;i<=n;++i){
		f(tot+a[i],max(maxx,a[i]),i,num+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
    sort(a+1,a+1+n,cmt);
    for(int i=1;i<=n;++i){
    	f(a[i],a[i],i,i);
	}
    cout<<res;
	return 0;
}
//5 1 2 3 4 5