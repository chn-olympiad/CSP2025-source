#include<bits/stdc++.h>
using namespace std;
string a[200005][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,q;
	long long ans=0;
	string x,y;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2];
	}
	for(int ii=1;ii<=q;ii++){
		ans=0;
		cin>>x>>y;
		int t=x.size();
		for(int i=1;i<=t;i++){
			int f=0;
			for(int j=1;j<i;j++){
				if(x[j-1]!=y[j-1]){
					f=1;
					break;
				}
			}
			if(f==1)continue;
			for(int j=i;j<=t;j++){
				int f1=0;
				for(int k=j+1;k<=t;k++){
				if(x[k-1]!=y[k-1]){
					f1=1;
					break;
				}
			    }
			    if(f1==1)continue;
			    string s="",s1="";
			    for(int k=i;k<=j;k++){
					s+=x[k-1];
					s1+=y[k-1];
				}
				for(int i=1;i<=n;i++){
					if(s==a[i][1]&&s1==a[i][2])ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
    return 0;
}
