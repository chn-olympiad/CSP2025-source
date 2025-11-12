#include<bits/stdc++.h>
using namespace std;
const int N=2e5+25;
int n,q;
string s[2][N],ft,st;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[0][i]>>s[1][i];
	while(q--){
		int ans=0;
		cin>>ft>>st;
		int fl=ft.size(),sl=st.size();
		if(fl!=sl){
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<fl;j++){
				int k=ft.find(s[0][i],j);
				if(k<0||k>=fl)break;
				string ss=ft;
				int len=s[0][i].size();
				for(int l=k;l<k+len;l++)ss[l]=s[1][i][l-k];
				if(ss==st){
					ans++;
					break;
				}
				j=k;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
