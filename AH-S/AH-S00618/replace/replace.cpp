#include<bits/stdc++.h>
using namespace std;
int n,q,cnt;
bool f[2005][2005];
map<string,string> a;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		a[x]=y;
	}
	for(int i=1;i<=q;i++){
		cnt=0;
		string x,y;
		cin>>x>>y;
		int len1=x.size();
		int len2=y.size();
		if(len1!=len2){
			cout<<0<<'\n';
			continue;
		}
		string l="",r="";
		for(int i=0;i<len1;i++){
			//l+=x[i];
			for(int j=0;j<=i;j++){
				l="";
				for(int k=0;k<j;k++){
					l+=x[k];
				}
				r="";
				for(int k=i+1;k<len2;k++){
					r+=x[k];
				}
				string ls1="",ls2="";
				for(int k=j;k<=i;k++){
					ls1+=x[k];
					ls2+=y[k];
				}
				
				//cout<<l<<' '<<ls2<<' '<<r<<'\n';
				if(l+ls2+r!=y) continue;
				//if(f[i][j]==1) continue;
				for(int k=1;k<=n;k++){
					if(a[ls1]==ls2 && f[i][j]==0){
						cnt++;
						f[i][j]=1;
						//cout<<i<<' '<<j<<'\n';
						//cout<<ls1<<' '<<ls2<<'\n';
					}
				}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
