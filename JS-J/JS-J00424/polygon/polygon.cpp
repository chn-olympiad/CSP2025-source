#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
const int MOD=998244353;
int pai[5010];
int ans=0;
bool pan(int x){
    int maxa=-1,sum=0;
    for(int i=1;i<=x;i++){
        if(pai[i]>maxa){
            maxa=pai[i];
            sum+=pai[i];
        }
    }
    if(sum>2*maxa) return true;
    else return false;
}
void fang(int i,int d,int l){
    if(d>i){
        if(pan(i)) ans=(ans+1)%MOD;
    }
    for(int j=l+1;j<=n;j++){
        pai[d]=a[j];
        fang(i,d+1,j);
    }
}
int main(){
    freopen("polygon.in","r",stdin);//666 cha dian bu hui xie
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	for(int i=3;i<=n;i++){
        fang(i,1,0);
	}
	cout<<ans;
	return 0;
}
