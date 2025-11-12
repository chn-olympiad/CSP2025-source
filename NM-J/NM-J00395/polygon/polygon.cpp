#include<bits/stdc++.h>
using namespace std;
int a,x[5007],y[5007],jg;
void v(int he,int lm,int cs,int csxb){
	if(he>lm*2 && cs>=3){
		jg++;jg%=998244353;
	}if(cs==a+1)return;
	for(int i=csxb+1;i<=a;i++){
		v(he+x[i],max(lm,x[i]),cs+1,i);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>a;
    int ma=-1;
    for(int i=1;i<=a;i++){
		cin>>x[i];ma=max(ma,x[i]);
	}if(ma==1){
		for(int i=3;i<=a;i++){
			jg+=(i-1)*(i-2)/2;jg%=998244353;
		}
		cout<<jg<<endl;
		return 0;
	}
	for(int i=1;i<=a;i++){
		v(x[i],x[i],1,i);
	}cout<<jg<<endl;
    return 0;
}
