#include<iostream>
#include<unordered_map>
#include<cstring>
using namespace std;
int n,q,ans;
unordered_map<string,string> dic(200005);
int main(){
	freopen("replace3.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s,ss;
		cin>>s>>ss;
		dic[s]=ss;
	}
	for(int i=1;i<=q;i++){
		ans=0;
		string que,tar;
		cin>>que>>tar;
		que=" "+que;
		for(int l=1;l<=que.size();l++){
			for(int r=l;r<que.size();r++){
				//cout<<l<<" "<<r<<" ";
				//cout<<que.substr(l,r-l+1)<<" ";
				//cout<<dic.count(que.substr(l,r-l+1))<<endl;
				if(dic.count(que.substr(l,r-l+1))){
					//cout<<que.substr(1,l-1)+dic[que.substr(l,r-l+1)]+que.substr(r+1,que.size()-r)<<endl;
					if(que.substr(1,l-1)+dic[que.substr(l,r-l+1)]+que.substr(r+1,que.size()-r)==tar){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
