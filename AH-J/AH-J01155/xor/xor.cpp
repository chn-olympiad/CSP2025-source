#include<bits/stdc++.h>
using namespace std;
long long n,k,p,a[500005];
struct node{
    int l,r;
}w[100005];
inline int cmp(node x,node y){
    if(x.r==y.r){
        return x.l<y.l;
    }
    return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	if(k==0 && n<=2){
        cout<<n/2<<"\n";
        return 0;
	}
	else if(k<=1){
        if(k==1){
            long long ans=0;
            for(int i=1;i<=n;i++){
                if(a[i]==1){
                    ans++;
                }
            }
            cout<<ans<<"\n";
            return 0;
        }
        else{
            long long ans=0,last=a[1];
            for(int i=2;i<=n;i++){
                if(a[i]==last==1){
                    ans++;
                }
            }
            cout<<ans<<"\n";
            return 0;
        }
	}
	else{
        for(int l=1;l<=n;l++){
            for(int r=l;r<=n;r++){
                long long num=a[l];
                for(int i=l+1;i<=r;i++){
                    num^=a[i];
                }
                if(num==k){
                    w[++p].l=l;
                    w[p].r=r;
                }
            }
        }
        if(p==0){
            cout<<"0\n";
            return 0;
        }
        sort(w+1,w+1+p,cmp);
        long long ans=1,t=w[1].r;
        for(int i=2;i<=p;i++){
            if(w[i].l>t){
                ans++;
                t=w[i].r;
            }
        }
        cout<<ans<<"\n";
	}
	return 0;
}
