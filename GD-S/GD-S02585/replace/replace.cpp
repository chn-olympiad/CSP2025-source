#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 200005
int n,q,ans,pos;
string s1[N],s2[N],q1,q2;
signed main(){
	double startt=clock();
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>q1>>q2;
		ans=0;
		for(int j=1;j<=n;j++){
			if(clock()-startt>989) break;
			int pos=0;
			while(q1.find(s1[j],pos)<1e9){
				int newpos=q1.find(s1[j],pos);
//				cout<<"found at:"<<newpos<<endl;
				for(int i=newpos;i<newpos+s1[j].size();i++){
					q1[i]=s2[j][i-newpos];
				}
//				cout<<q1<<" "<<q2;
				if(q1==q2) ans++;
				for(int i=newpos;i<newpos+s1[j].size();i++){
					q1[i]=s1[j][i-newpos];
				}
//				cout<<" -->"<<q1<<endl;
				pos=newpos+1;
				
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
