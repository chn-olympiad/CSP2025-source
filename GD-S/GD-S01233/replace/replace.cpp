#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int N=10005;
string s[N],t[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	if(n>10000){
		while(q--){
			cout<<"0\n";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		string s3;
		int sz=s1.size();
		long long ans=0;
		for(int i=1;i<=n;i++){
			int len=s[i].size();
//			len--;
//			bool flag=1;
			for(int j=0;j<=sz-len;j++){
//				s3=s1;
				bool flg=1;
//				cout<<len<<"jjj\n";
				for(int k=j;k<=j+len-1;k++){
					if(s[i][k-j]!=s1[k]){
//						cout<<s[i][k]<<" "<<s1[k-j]<<" lll\n";
						flg=0;
//						cout<<i<<" lll\n";
						break;
					}
				}
				if(flg==1){
//					cout<<i<<" "<<len<<" qw\n";
//					cout<<"qwq\n";
					for(int k=j;k<=j+len-1;k++){
						s3[k]=t[i][k-j];
					}
//					cout<<s3<<" ppp\n";
					if(s3==s2){
//						cout<<i<<" qwq\n";
//						cout<<s3<<" "<<s2<<" qwq\n";
						ans++;
					}
					s3=s1;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
