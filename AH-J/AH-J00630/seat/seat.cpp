#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],ans=1,t,s1,s2;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d%d",&n,&m,&t);
    a[1]=t;
    for(int i=2;i<=n*m;i++) {
		scanf("%d",&a[i]);	
		if(a[i]>t) ans++;
	}
     s1=ans/n;
     s2=ans%n;
	if(s1%2==1&&s2!=0) cout<<s1+1<<" "<<n+1-s2;
	else if(s1%2==1&&s2==0) cout<<s1<<" "<<n;
	else if(s1%2==0&&s2==0) cout<<s1<<" "<<1;
	else cout<<s1+1<<" "<<s2;
}
