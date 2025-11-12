#include<bits/stdc++.h>
#define int long long
using namespace std;

int read(){
	int cnt=0;
	bool f=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=!f;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		cnt=cnt*10+c-'0';
		c=getchar();
	}
	return ((f==0)?cnt:-cnt);
}

void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar((char)(x%10+'0'));
}

int n,m;

string a[200005],b[200005];

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0)->sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(m--){
		string x,y;
		cin>>x>>y;
		int sum=0; 
		for(int i=1;i<=n;i++){
			bool f=0,flag=1;
			int l=a[i].length(),l2=x.length(),id=0;
			for(int j=0,k=0;j<l&&k<l2;){
				if(a[i][j]==x[k]){
					if(id==0)id=k-1;
					k++;
					j++;
					f=1;
				}else if(f==0){
					k++;
				}else{
					flag=0;
					break;
				}
			}
			if(flag){
				string qian=x.substr(0,id+1);
				string hou="";
				if(id+l+1>=l2)hou="";
				else hou=x.substr(id+l+1);
				string ans=qian+b[i]+hou;
				if(ans==y)sum++;
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}

