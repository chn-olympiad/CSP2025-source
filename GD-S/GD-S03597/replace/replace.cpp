#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		string q1,q2;
		cin>>q1>>q2;
		if(q1.size()!=q2.size()){
			cout<<0<<endl;
			continue;
		}
		int len=q1.size();
		int sum=0;
		for(int i=0;i<n;i++){
			int t=0;
			int f=0;
			for(int j=0;j<len;j++){
				if(q1[j]==s[i][0][t] && q2[j]==s[i][1][t]){
					t++;
					if(t==s[i][0].size()){
						f++;
						t=0;
					}
				}
				else if(q1[j]!=q2[j]){
					f=2;
					break;
				}
				else{
					t=0;
					if(q1[j]==s[i][0][t] && q2[j]==s[i][1][t]){
						t++;
						if(t==s[i][0].size()){
							f++;
							t=0;
						}
					}
					else if(q1[j]!=q2[j]){
						f=2;
						break;
					}
				}
			}
			if(f==1)sum++;
		}
		cout<<sum<<endl;
	}
}
