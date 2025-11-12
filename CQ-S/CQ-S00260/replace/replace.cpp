#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
string a[200005][2];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2];
	}
	while(q--){
		string st,ed;
		cin>>st>>ed;
		int cnt=0;
		for(int i=0;i<st.size();i++){
			for(int j=i+1;j<st.size();j++){
				string nw="";
				for(int k=i;k<=j;k++)nw+=st[k];
				for(int k=1;k<=n;k++){
					if(nw==a[k][1])nw=a[k][2];
				}
				string now="";
				for(int k=0;k<i;k++)now+=st[k];
				now+=nw;
				for(int k=j+1;k<st.size();k++)now+=st[k];
				if(now==ed){
					cnt++;
				}
//				cout<<now<<"\n";
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
