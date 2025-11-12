#include<bits/stdc++.h>
using namespace std;
int n,o,ans,q,w,e,b1,b2,b3;
struct aa{
	int M,C,S,H;
}a[100024];
bool bb(aa x,aa y){
	if(x.H>y.H)return 1;
	else if(x.M<y.M)return 1;
	else if(x.C<y.C&&x.M==y.M)return 1;
	else return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>o;
	for(int i=1;i<=o;i++){
		cin>>n;
		ans=0;
		q=0;
		w=0;
		e=0;
		for(int j=1;j<=n;j++){
			cin>>b1>>b2>>b3;
			a[j].M=max(b1,max(b2,b3));
			a[j].S=min(b1,min(b2,b3));
			a[j].C=b1+b2+b3-a[j].M-a[j].S;
			a[j].H=a[j].M-a[j].C;
		}sort(a+1,a+n+1,bb);
		for(int j=1;j<=n;j++){
			if(q<n/2){
				ans+=a[j].M;
				q++;
			}else if(w<n/2){
				ans+=a[j].C;
				w++;
			}
			a[j].M=0;
			a[j].C=0;
			a[j].S=0;
		}
		cout<<ans<<endl;
	}
}
