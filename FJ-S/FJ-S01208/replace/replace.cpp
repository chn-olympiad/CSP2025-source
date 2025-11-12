#include<bits/stdc++.h>
using namespace std;
long long n,m,k,sum=0;
string s[15135],ss[15135],s1[11455],s2[11455];
int kmp(){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(s[j]==s1[i]&&ss[j]==s2[i]){
				sum++;
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>s[i]>>ss[i];
	for(int i=0;i<m;i++)cin>>s1[i]>>s2[i];
	kmp();
	cout<<sum;
	return 0;
}
