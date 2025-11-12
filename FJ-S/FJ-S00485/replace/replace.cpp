#include<bits/stdc++.h>
using namespace std;string a[1000000],b[1000000];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++){
		string c,d;int x,y;long long ans=0;
		cin>>c>>d;
		for(int j=1;j<=n;j++){y=0;
			while(1){string e=c;
				x=c.find(a[j],y);y=x+1;
				if(x>=c.size())break;
				for(int z=0;z<a[j].size();z++){
					e[z+x]=b[j][z];
				}
				if(d==e)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}