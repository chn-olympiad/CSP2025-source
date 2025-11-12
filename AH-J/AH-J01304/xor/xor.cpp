#include<bits/stdc++.h>
using namespace std;
long long n,k,s,c,q,maxn,cnt,h1,h2,fh;
long long a[500010];
struct fun{
	long long x,y;
}b[500010];
bool cmp(fun a,fun b){
	return a.x<b.x;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			fh++;
		}
	}
	if(k==0&&fh==n){
		cout<<n/2;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		s^=a[i];
		//cout<<'*'<<s<<endl;
		if(s==k){
			c++;
			b[c].x=1;
			b[c].y=i;
			//cout<<c<<' '<<b[c].x<<' '<<b[c].y<<endl;
		}
		q=s;
		for(long long j=1;j<=i-1;j++){
			q^=a[j];
			if(q==k){
				c++;
				b[c].x=j+1;
				b[c].y=i;
				//cout<<c<<' '<<b[c].x<<' '<<b[c].y<<endl;
			}
		}
	}
	sort(b+1,b+c+1,cmp);
	for(long long i=1;i<=c;i++){
		cnt=1;
		h1=b[i].x;
		h2=b[i].y;
		for(long long j=1;j<=c;j++){
			if(j<i){
				if(b[j].y<h1){
					cnt++;
					h1=b[j].x;
					h2=b[i].y;
					//cout<<'&'<<i<<' '<<j<<' '<<b[i].x<<' '<<b[i].y<<' '<<b[j].x<<' '<<b[j].y<<endl;
			    }
			}
			else{
				if(i!=j&&h2<b[j].x){
					cnt++;
					h1=b[j].x;
					h2=b[j].y;
					//cout<<'&'<<i<<' '<<j<<' '<<b[i].x<<' '<<b[i].y<<' '<<b[j].x<<' '<<b[j].y<<endl;
			    }
			}
		}
		maxn=max(maxn,cnt);
		//cout<<'$'<<i<<' '<<cnt<<' '<<maxn<<endl;
	}
	cout<<maxn;
}
