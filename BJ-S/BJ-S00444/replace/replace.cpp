#include<bits/stdc++.h>
#include<string>
#include<map>
using namespace std;
int n,q;

//string s[100][3];
map<string,string> mp;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(q--){
		int cnt=0;
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()) {
			cout<<0<<"\n";
			continue;
		}
		int len=s1.size();
		for(int i=0;i<len;i++){
			for(int j=i;j<len;j++){
				string s;
				//cout<<s1<<"s1\n";
				//cout<<s1.substr(i,j+1);
				for(int k=i;k<=j;k++){
					s+=s1[k];
				}
				//cout<<"\n";
				//cout<<i<<" "<<j<<"\n";
				//cout<<s<<"\n";
				
				if(mp.count(s)){
					
					string news=s1;
					string th=mp[s];
					
					//cout<<th<<"\n";
					for(int l=i,r=0;l<=j;l++,r++){
						//cout<<"now"<<l<<"\n";
						news[l]=th[r];
					}
					//cout<<news<<"newa\n";
					if(news==s2) cnt++;
				}
			}
		}
		cout<<cnt;
		cout<<"\n";
	}
	return 0;
}

