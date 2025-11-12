#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,lp,rp;
long long ans=0;
struct node{
	string a,b;
}g[N];
string x,y;
bool cmp(node a,node b){
	return a.a.length()>b.a.length();
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>g[i].a>>g[i].b;
	}
	sort(g+1,g+1+n,cmp);
	while(q--){
		ans=0;
		cin>>x>>y;
		x='*'+x+'*';
		y='*'+y+'*'; 
		lp=0,rp=x.length();
		rp--;
		//cout<<rp<<endl;
		for(;lp<=x.length()-3;lp++){
			if(x[lp]!=y[lp]) break;
			for(rp=x.length()-1;rp>lp+1;rp--){
				if(x[rp]!=y[rp]) break;
				//cout<<lp<<" "<<rp<<endl;
				for(int k=1;k<=n;k++){
					if(rp-lp-1>g[k].a.length()){
						break;
					}else if(rp-lp-1==g[k].a.length()){
						//cout<<k<<endl;
						string t1=g[k].a,t2=g[k].b;
						for(int i=lp+1;i<=rp-1;i++){
							if(x[i]==t1[lp+1-i]&&y[i]==t2[lp+1-i]){
								ans++;
							}else{
                                break;
							}
						}
					}
				}
			}
			//cout<<"next"<<endl;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
