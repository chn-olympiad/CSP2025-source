//GZ-S00353 贵阳市第一中学 程思淇 
#include<bits/stdc++.h>
using namespace std;
struct huan{
	string s1,s2;
}h[200001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout)
	int n=0,q=0,ans=0;
	cin>>n>>q;
	string x="",y="",a="",b="",c="";
	for(int i=1;i<=n;i++){
		cin>>h[i].s1>>h[i].s2;
	}
	for(int i=1;i<=q;i++){
		ans = 0;
		cin>>x>>y;
		int len1 = x.size();
		if(y.size() != len1){
			cout<<0<<endl;
		}
		else{
			for(int j=0;j<len1;j++){
				a="";
				b="";
				c="";
				for(int j1=0;j1<j;j1++){
					a = a+x[j1];
				}
				for(int k=1;k<=len1;k++){
					b = "";
					c = "";
					for(int j1=a.size()+k;j1<len1;j1++){
						c = c+x[j1];
					}
					for(int j1 = a.size();j1<a.size()+k;j1++){
						b = b+x[j1];
					}
					for(int z=1;z<=n;z++){
						if(b==h[z].s1){
							if(a+h[z].s2+c == y) ans++;
						}
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
