#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s[N][3]; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			int r1=0,r2=0,l1=t1.size(),l2=s[i][1].size();
			if(l1<l2)
				continue;
			string t3=t1;
			for(int j=0;j+l2-1<=l1;j++){
				bool f=1;
				int l=0;
				for(int k=j;k<=j+l2-1&&f;k++,l++){
					if(t1[k]==s[i][1][l])
						t3[k]=s[i][2][l];
					else{
						f=0;
						break;
					}
				}
				if(f&&t3==t2){
					ans++;
					break; 
				}
				t3=t1;
			}
			
		}
		cout<<ans<<endl;
	}
	return 0;
}
