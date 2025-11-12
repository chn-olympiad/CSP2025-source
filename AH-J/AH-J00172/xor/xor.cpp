#include<bits/stdc++.h>
using namespace std;
struct s{
    long long l,r;
}zu[5000010];
long long a[500010],xb=0;
bool cmp(s x,s y){
    if(x.r!=y.r){
        return x.r<y.r;
    }else{
        return x.l<y.l;
    }
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	for(int i=1;i<=n;i++){
        long long x=0;
        for(int j=i;j<=n;j++){
            x=x^a[j];
            if(x==k){
                xb++;
                zu[xb].l=i;
                zu[xb].r=j;
                break;
            }
        }
	}
    sort(zu+1,zu+xb+1,cmp);
    long long cnt=0,rrr=0;
    for(int i=1;i<=xb;i++){
        if(zu[i].l>rrr){
            cnt++;
            rrr=zu[i].r;
        }
    }
    cout<<cnt;
	return 0;
}
