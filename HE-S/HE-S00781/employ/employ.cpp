#include<bits/stdc++.h>
using namespace std;
int n,m,res,p[550],f,h;
string s;
int c[550],x=1,d;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}for(int i=1;i<=n;i++){
		cin>>c[i];
	}for(int i=1;i<=n;i++){
		p[i]=x;
		x++;
	}for(int i=1;i<=n;i++){
		if(s[i]==1) d++;
	}
	if(d=n) cout<<n;
	else{
	if(m==1&&s[1]!=1||m==1&&c[1]!=1)cout<<n;
	else{
		for(int i=1;i<=n;i++){
		if(s[i]==0) f++;
		else h++;
		if(f>=c[i]){
			f++;
		}else h++;
	}if(h>=m) res++;
	else{
		
	}
	cout<<res%998244353;
	}
	}
	
	return 0;
}
