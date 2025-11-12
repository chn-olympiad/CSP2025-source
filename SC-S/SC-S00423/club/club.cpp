#include<bits/stdc++.h>
using namespace std;
int t,n,ans; int f1,f2,f3;
struct value{
	int _1,_2,_3;
}v[100005];
bool cmp(value a,value b){ return a._1+a._2+a._3<b._1+b._2+b._3; }
int main(){
	freopen("club.in","r",stdin); freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0; cin>>n;
		for(int i=1;i<=n;i++) cin>>v[i]._1>>v[i]._2>>v[i]._3;
		sort(v+1,v+n+1,cmp);
		for(int i=1;i<=n;i++){
			if((f1!=n/2||f2!=n/2||f3!=n/2)&&f1+f2+f3!=n){
				int maxn=max({v[i]._1,v[i]._2,v[i]._3});
				if(maxn==v[i]._1) f1++,ans+=maxn;
				else if(maxn==v[i]._2) f2++,ans+=maxn;
				else f3++,ans+=maxn;
			}
		} cout<<ans<<endl;
	} 
	fclose(stdin); fclose(stdout);
	return 0;
}