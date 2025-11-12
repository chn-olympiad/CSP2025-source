#include<bits/stdc++.h>
using namespace std;
template<typename type>
inline void read(type &x){
	x=0;bool flag(0);char ch=getchar();
	while(!isdigit(ch)) flag=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	flag?x=-x:0;
}
const int N=2e5+10;
int n,q,ans;
int a[N][3];
string x,y; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n),read(q);
	for(int i=1;i<=n;i++){
		cin>>x;
		cin>>y;
		a[i][0]=x.size();
		for(int j=0;j<a[i][0];j++){
			if(x[j]=='b'){
				a[i][1]=j;
				break;
			}
		}
		for(int j=0;j<a[i][0];j++){
			if(y[j]=='b'){
				a[i][2]=j;
				break;
			}
		}
		x.clear();
		y.clear();
	}
	for(int i=1,len,l1,l2;i<=q;i++){
		ans=0;
		cin>>x;
		cin>>y;
		len=x.size();
		for(int j=0;j<len;j++){
			if(x[j]=='b'){
				l1=j;
				break;
			}
		}
		for(int j=0;j<len;j++){
			if(y[j]=='b'){
				l2=j;
				break;
			}
		}
		int c=l1-l2;
		for(int i=1;i<=n;i++){
//			cout<<a[i][0]<<" "<<a[i][1]<<" "<<a[i][2]<<endl;
//			cout<<len<<" "<<l1<<" "<<l2<<endl;
			if(a[i][1]-a[i][2]==c&&a[i][1]<=l1&&a[i][0]<=len) ans++;
		}
		printf("%d\n",ans);
		x.clear();
		y.clear();
	}
	return 0;
}

