#include<bits/stdc++.h>
using namespace std;

struct tg{
	   string s1,s2;
};tg a[200005];

int main(){
				freopen("replace.in","r",stdin);
				freopen("replace.out","w",stdout);
				int n,q;
				cin>>n>>q;
				for(int i=1;i<=n;i++){
					cin>>a[i].s1>>a[i].s2;
				}
				while(q--){
								int cnt=0;
								string x1,x2;
								cin>>x1>>x2;
								for(int i=1;i<=n;i++){
												if(a[i].s1.size()<=x1.size()) cnt++;
								}
								cout<<cnt<<endl;
				}
				return 0;
}

