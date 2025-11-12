#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],b[100005],c[100005],d[100005],cnt,o,p,q,x,y,z;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>m;
	while(m--){
		cin>>n;
		o=n*0.5;p=n*0.5;q=n*0.5;
		x=0;y=0;z=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			cnt=max(a[i],max(b[i],c[i]));
			if(cnt==a[i]&&o!=0){
				o--;
				x+=a[i];
				continue;
			}
			if(cnt==b[i]&&p!=0){
				p--;
				y+=b[i];
				continue;
			}
			if(cnt==c[i]&&q!=0){
				q--;
				z+=c[i];
				continue;
			}
		}
		cout<<x+y+z<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
