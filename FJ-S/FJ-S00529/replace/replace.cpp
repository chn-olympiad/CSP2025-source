#include<bits/stdc++.h>
using namespace std;
struct coco{
	string y1,y2;
}s[1000024];
long long n,m;
string x,y; 
long long tihuan(string a,string b){
	string x,z;
	long long ans=0;
	for(int i=1;i<=n;i++)if(s[i].y1==a&&s[i].y2==b)ans++;
	long long l=0,r=a.size()-1;
	while(l<=r){
		if(a[l]!=b[l]&&a[r]!=b[r]){
			break;
		}
		if(a[l]==b[l]){
			x+=a[l];
			l++;
		}if(a[r]==b[r]){
			z+=a[r];
			r--;
		}for(int i=1;i<=n;i++){
			string v=x+s[i].y1+z,w=x+s[i].y2+z;
			if(v==a&&w==b)ans++;
		}
	}return ans;
}int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i].y1>>s[i].y2;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		long long ans=tihuan(x,y);
		cout<<ans<<endl;
	}
	return 0;
}

