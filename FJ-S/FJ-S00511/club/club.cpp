#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int T;//5
int n;
int a[N],b[N],c[N];
int t[N];
int x,y,z;
int tot=0;
priority_queue<int>p;
 
void change(){
	int len=max(x,max(y,z));
	if(len==y){
		for(int i=1;i<=n;++i)t[i]=b[i];
		for(int i=1;i<=n;++i)b[i]=a[i];
		for(int i=1;i<=n;++i)a[i]=t[i];
		swap(x,y);
	}
	else if(len==z){
		for(int i=1;i<=n;++i)t[i]=c[i];
		for(int i=1;i<=n;++i)c[i]=a[i];
		for(int i=1;i<=n;++i)a[i]=t[i];
		swap(x,z);
	}
	
}


int main(){

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	cin>>T;
	while(T--){
		cin>>n;
		int cnt=0;
		for(int i=1;i<=n;++i){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i])++x,cnt+=a[i];
			else if(b[i]>=a[i]&&b[i]>=c[i])++y,cnt+=b[i];
			else ++z,cnt+=c[i];
		}
		
		change();
//		cout<<x<<" "<<y<<" "<<z<<"\n";
//		for(int i=1;i<=x;++i)
//			cout<<a[i]<<" ";
//		cout<<"\n";
//		for(int i=1;i<=y;++i)
//			cout<<b[i]<<" ";
//			cout<<"\n";
//		for(int i=1;i<=z;++i)
//			cout<<c[i]<<" ";
		//cout<<"\n";
	
		for(int i=1;i<=n;++i){
			if(a[i]>=b[i]&&a[i]>=c[i]){
				p.push(b[i]-a[i]);
				p.push(c[i]-a[i]);
			}
			//cout<<b[i]<<" "<<a[i]<<"\n";
		}
		//cout<<cnt<<"\n";
		//cout<<n<<" "<<x<<"\n";
		for(int i=1;i<=max(0,x-n/2);++i){
			int k=p.top();
			//cout<<k<<" ";
			cnt+=k;
			p.pop();
			//cout<<k;
		}
		cout<<cnt<<"\n";
		while(!p.empty())p.pop();
		x=0,y=0,z=0;
	}
	
	return 0;
}
