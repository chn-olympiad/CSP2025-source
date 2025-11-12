#include<bits/stdc++.h>
using namespace std;
int n,k,ans=-1;
int a[500005],b[500005];
struct m{
	int x;
	int y;
}p[500005];
int mp(m a,m b){
	return a.x<b.x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	int top,s,l;
	for(int i=1;i<=n;i++){
		top=1,s=1;
		for(int j=i;j<=n;j++){
			s^=a[j];
			top^=a[j];
			if(s==k||top==k){
				p[++l].x=i;
				p[l].y=j;
				s=1;
			}
		}
	}
	sort(p+1,p+l+1,mp);
	for(int i=1;i<=l;i++){
		int at=p[i].x,bt=p[i].y;
		s=0;
		for(int j=i+1;j<=l;j++){
		    if(bt<p[j].x){
		    	at=p[j].x;
		    	bt=p[j].y;
		    	s++;
			}	
		}
		ans=max(ans,s);
	}
	cout<<ans;
	return 0;
} 
