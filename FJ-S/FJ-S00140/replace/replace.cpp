#include<bits/stdc++.h>
using namespace std;
long long n,as,ans;
struct node {
	string x,y;
	long long l;
} a[100005],q[100005];
long long x[100005],y[100005];
string qa[100005],qb[100005];
inline long long read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch==45)f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void so() {
	cin>>n>>as;
	for(int i=1; i<=n; i++) {
		cin>>a[i].x>>a[i].y;
		a[i].l=a[i].x.size();
		a[i].x='#'+a[i].x;
		a[i].y='#'+a[i].y;
	}
	for(int i=1; i<=as; i++) {
		cin>>q[i].x>>q[i].y;
		q[i].l=q[i].x.size();
		q[i].x='#'+q[i].x;
		q[i].y='#'+q[i].y;
	}
	for(int i=1; i<=as; i++) {
		ans=0;
		//cout<<i<<" : \n";
		for(int j=1;j<=n;j++){
			//cout<<j<<" : \n";
			for(int k=1;k<=q[i].l-a[j].l+1;k++){
				bool ff=1;
				//cout<<k<<" \n";
				for(int p=1;p<k&&ff;p++){
					if(q[i].x[p]!=q[i].y[p])ff=0;
				}
				for(int f=0;f<=a[j].l-1&&ff;f++){
					long long i1=f+1;
					long long i2=f+k;
					//cout<<a[j].x[i1]<<' '<<q[i].x[i2]<<' '<<a[j].y[i1]<<' '<<q[i].y[i2]<<'\n';
					if(a[j].x[i1]!=q[i].x[i2]||a[j].y[i1]!=q[i].y[i2]){
						ff=0;
					}
				}
				for(int p=k+a[j].l;p<=q[i].l&&ff;p++){
					if(q[i].x[p]!=q[i].y[p])ff=0;
				}
				if(ff)ans++;
			}
		}
		cout/*<<"\n"<<x[i]<<" "<<y[i]<<' '*/<<ans<<'\n';
	}
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	so();
	return 0;
}
