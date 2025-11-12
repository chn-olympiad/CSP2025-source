#include<bits/stdc++.h>
using namespace std;
int n,m,l,h,a[1005],id,cnt;
int main() { 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int u=a[1];
    sort(a+1,a+n*m+1);
    for(int i=n*m;i>=1;i--) 
    {
		if(a[i]==u) {id=cnt+1; break;}
		else cnt++;
	}
    if(id%n==0) l=id/n;
    else l=id/n+1;
    if(l%2==0) { 
		if(id%n==0) h=1;
		else h=n-(id%n)+1;
	}
    else { 
		if(id%n==0) h=n;
		else h=id%n;
	} cout<<l<<" "<<h;
    return 0;
}
