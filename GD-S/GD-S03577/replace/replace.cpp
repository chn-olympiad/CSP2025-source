#include<bits/stdc++.h>
using namespace std;
int n,m,k,t,q,ans; string t1,t2;


struct klo{
	string a,b;
}bp[200005];


int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n>>q;
	for(int i = 1;i<=n;i++)cin >> bp[i].a >> bp[i].b;
	for(int i = 1;i<=q;i++){
		cin >> t1 >> t2;
		string h,b;bool o= 0,l = 0;
		for(int j =0;j<t1.size();j++){
			if(t1[j] != t2[j]){
				h = h+t2[j];o = 1;b= b+t1[j];
			}
			else if(o){
				cout << 0<<endl;l = 1;break;
			}
		}
		if(l)continue;

		
		
		for(int i =1;i<=n;i++){
			if(h.size() == bp[i].a.size()){
				bool yui = 0;
				for(int j =0;j<h.size();j++){
					if(b[j]!=bp[i].a[j]){
					yui = 1;break;}
				}
				if(yui)break;
				
				for(int j = 0;j<h.size();j++){
					if(h[j] == bp[i].b[j]){
						t++;
					}
				}
				if(t == bp[i].b.size()){
				
					ans++;
				}
			
			}
			
		}cout << ans<<"\n";
	
	
	
	}
	
	return 0;
}
