#include<bits/stdc++.h>
#define ll long long
#define N 1000010
#define M 1010
using namespace std;
ll n,m,a[N],g=1,b[N],s,d,v=1,k,f,h;
struct q{
    ll start;
    ll enddd;
}c[N];
map<ll,ll>o,p;
int main(){
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>a[i];
        h=max(a[i],h);
        if(a[i]!=1){
            g=0;
        }
        if(a[i]==1){
            ++d;
        }

        if(a[i]>=2){
            v=0;
        }
        b[i]=b[i-1]^a[i];
	}
	if(g){
        cout<<n/2<<endl;
        return 0;
	}
	if(v){
        if(m==1){
            cout<<d<<endl;
        }
        else{
            cout<<d/2+n-d<<endl;
        }
        return 0;
	}
	for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(b[i]^b[j-1]==m){
                q w;
                w.start=j;
                w.enddd=i;
                c[++f]=w;
                if(o[w.start]>0){
                    if(c[o[w.start]].enddd>w.enddd){
                        o[w.start]=f;
                    }
                    else{
                        continue;
                    }
                }
                o[w.start]=f;
            }
        }
	}
    for(int i=1;i<=h;i++){
        if(o[i]>0){
            i+=c[o[i]].enddd;
            ++s;
        }
    }
	cout<<s<<endl;
    return 0;
}
