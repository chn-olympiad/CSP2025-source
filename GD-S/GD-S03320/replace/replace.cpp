#include<bits/stdc++.h>
using namespace std;

int n,q;
struct du{
	string a,b;
};
du st[200001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>st[i].a>>st[i].b;
	while(q--){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		while(t1[0]==t2[0]){
			for(int i=1;i<=n;i++){
				if(st[i].a==t1 && st[i].b==t2)
					ans++;
			}
			t1.erase(0,1);
			t2.erase(0,1);
		}
		int r1=t1.length()-1,r2=t2.length()-1;
		while(t1[r1]==t2[r2]){
			for(int i=1;i<=n;i++){
				if(st[i].a==t1 && st[i].b==t2)
					ans++;
			}
			t1.erase(r1,1);
			t2.erase(r2,1);
			r1--;
			r2--;
		}
		for(int i=1;i<=n;i++){
			if(st[i].a==t1 && st[i].b==t2)
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
