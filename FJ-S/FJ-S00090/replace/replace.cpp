#include<bits/stdc++.h>
using namespace std;

const int N=10015;
int n,m;
string r[N][2];

void init(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string str;
		cin>>str;
		r[i][0]=str;
		cin>>str;
		r[i][1]=str;
	}
}

void solve(){
	for(int q=1;q<=m;q++){
		int ans=0;
//		string qs,qs2;
//		cin>>qs>>qs2;
//		int len=qs.size();
//		string Y,Y2,K,K2;
//		for(int k=1;k<=n;k++){
//			bool f=0;
//			int j=0;
//			K="";K2="";
//			Y=r[k][0];Y2=r[k][1];
//			int lenh=r[k][0].size();
//			for(int g=0;g<lenh;g++)K+=qs[g],K2+=qs[g];
//			cout<<Y<<" "<<K<<" --- "<<Y2<<" "<<K2<<"\n";
//			if(Y==K&&Y2==K2){
//				ans++;
//				continue;
//			}
//			for(j=lenh;j<len;j++){
//				if(f==1&&qs[j]!=qs2[j])break;
//				if(Y==K&&Y2==K2)f=1;
//				K+=qs[j];K2+=qs2[j];
//				for(int g=0;g<j-lenh;g++)Y+=qs[g],Y2+=qs2[g];
//				Y+=r[k][0];Y2+=r[k][1];
//				cout<<Y<<" "<<K<<" --- "<<Y2<<" "<<K2<<"\n";
//			}
//			if(f==1&&j==len)ans++;
//		}
		cout<<ans<<"\n";
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	init();
	solve();
	return 0;
}

