#include<bits/stdc++.h>
using namespace std;
int yh(int x,int y){
	int cnt=0,p=1;
    if(x==y)return 0;
    if(x==0||y==0)return max(x,y);
    while(x>0&&y>0){
		int xx=x%2,yy=y%2;
		x>>=1,y>>=1;
	    if(xx!=yy)cnt+=p;
		p*=2;
	}
	return cnt+x*p+y*p;
}
int n,k,a[500005],d[500005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(k==0||k==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==k)ans++;
			else if(a[i-1]!=k&&a[i]-a[i-1]==k){
				ans++;
				a[i]=k;
			}
		}
		cout<<ans;
		return 0;
	}
    for(int i=1;i<=n;i++){
		d[i]=100000000;
		cin>>a[i];
		int l=a[i],r=i;
		while(l!=k&&r>0){
			r--;
			l=yh(l,a[r]);
		}
		d[r]=min(d[r],i);
	}
	int p=1;
	bool f=1;
	while(p<=n){
		for(int i=p;i<=d[p];i++)
		    if(d[i]<d[p]){
				p=i;
				f=0;
				break;
			}
		if(f==1)ans++,p++;
		else f=1;
	}
	cout<<ans;
    return 0;
}
