#include<iostream>
using namespace std;
const int N=2e5+2;
int n,Q;
string s[N][2],t1,t2,tmp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>Q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(Q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			tmp=t1;
			int pos=tmp.find(s[i][0]);
			if(pos<0)continue;
			int r=pos+s[i][0].size();
			for(int j=pos;j<r;j++){
				tmp[j]=s[i][1][j-pos];
			}
			if(tmp==t2)cnt++;
		}
		cout<<cnt<<endl;
	}
}
