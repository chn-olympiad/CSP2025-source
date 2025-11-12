#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
int n,q;
string str[N][2];
bool l[N],r[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>str[i][0]>>str[i][1];
	}
	for(int i=1;i<=q;i++){
		string p1,p2;
		cin>>p1>>p2;
		// cout<<"SDFSDFSDFSDF"<<endl;
		if(p1.size()!=p2.size()){
			cout<<"0"<<endl;
			continue;
		}
		for(int i=0;i<=p1.size();i++){
			l[i]=r[i]=0;
		}
		for(int i=0;i<p1.size();i++){
			if(p1[i]!=p2[i]){
				break;
			}
			l[i]=1;
		}
		for(int i=p1.size()-1;i>=0;i--){
			if(p1[i]!=p2[i]){
				break;
			}
			r[i]=1;
		}
		r[p1.size()]=1;
		/*for(int i=0;i<p1.size();i++){
			cout<<l[i]<<" ";
		}
		cout<<endl;
		for(int i=0;i<p1.size();i++){
			cout<<r[i]<<" ";
		}
		cout<<endl;*/
		int cnt=0;
		for(int j=1;j<=n;j++){
			bool isp=0;
			for(int k=0;k<p1.size();k++){
				if(str[j][0].size()+k-1>=p1.size()){
					break;
				}
				bool flag=true;
				for(int l=0;l<str[j][0].size();l++){
					if(p1[k+l]==str[j][0][l]&&p2[k+l]==str[j][1][l]){
						continue;
					}
					flag=false;
					break;
				}
				if(flag){
					/*cout<<j<<" "<<k<<" "<<" "<<l[k-1]<<" "<<
								r[str[j][0].size()+k]<<" "<<str[j][0].size()+k<<endl;*/
					if(((k>0&&l[k-1])||(k==0))&&(r[str[j][0].size()+k])){
						// cout<<"SDFSDF"<<endl;
						isp|=flag;
						break;
					}
				}
			}
			/*if(isp){
				cout<<str[j][0]<<" "<<str[j][1]<<endl;
			}*/
			cnt+=isp;
		}
		cout<<cnt<<endl;
	}
	return 0;
}