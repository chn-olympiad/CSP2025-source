#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[100010][2];
void solve1(){
	int sum=0;
	string s1,s2;
	cin>>s1>>s2;
	for(int i=1;i<=n;i++){
		int len1=s1.find(s[i][1]),len2=s2.find(s[i][2]);
		if(len1<0||len1>=s1.size()||len2<0||len2>=s2.size()) continue;
		if(len1!=len2) continue;
		int len=len1+s[i][1].size()-1;
		bool f=true;
		for(int i=len1-1;i>=0;i--){
			if(s1[i]!=s2[i]){
				f=false;
				break;
			}
		} 
		if(f==false) continue;
		for(int i=len+1;i<s1.size();i++){
			if(s1[i]!=s2[i]){
				f=false;
				break;
			}
		}
		if(f==false) continue;
		sum++;
	}
	cout<<sum;
}
int main(){
    freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
    while(q--){
    	solve1();
	}

	return 0;
}

