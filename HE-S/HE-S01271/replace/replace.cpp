#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=0;i<q;i++){
		string b1,b2;
		int ans=0;
		cin>>b1>>b2;
		for(int j=0;j<n;j++){
	//		if(b1.size()>s1[j].size()) continue;
	//		if(b2.size()>s2[j].size()) continue;
			if(b1.size()==s1[j].size()&&b1==s1[j]){
				if(b2.size()==s2[j].size()&&b2==s2[j]){
					ans++;
					break;
				}
			}
	//		for(int h=0;h<b1.size()-s1[j].size();h++){
	//			if(b1[h]==s1[j][0]){
	//				bool f=true;
	//				for(int m=0;m<s1[j].size();m++){
	//					if(b1[h]!=s1[j][m])  {
	//						f=false;
	//						break;
	//					}
	//					h++;
		//			}
		//			if(!f) break;
		//			else{
		//				ans++;
		//				break;
		//		}
		//	}
		//	}
			
		}
		cout<<ans<<endl;
	}
	return 0;
}
