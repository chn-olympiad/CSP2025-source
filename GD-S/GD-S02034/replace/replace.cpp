#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,q;
string s1[N],s2[N];
void solve(string a,string b){
	int num=0;
	int len1=a.size(),len2=b.size();
	for (int i=1;i<=n;i++){
		int k1=s1[i].size(),k2=s2[i].size();
		bool flag1=false;
		for (int j=0;j<a.size()-k1+1;j++){
			string ss=a.substr(j,k1);
			if(ss==s1[i]){
				string ss1=b.substr(j,k2);
				string t1=a.substr(0,j),t2=a.substr(j+k1,len1-j-k1);
				string t3=b.substr(0,j),t4=b.substr(j+k2,len2-j-k2);
				if(ss1==s2[i] && (t1==t3 &&t2==t4)){
					if(t1==""&&t2!="")
						continue;
					num++;
				}
			}
		}
	}
	cout <<num<<endl;	
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","out",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];	
	}
	while(q--){
		string _s1,_s2;
		cin>>_s1>>_s2;
		solve(_s1,_s2);
	}
}
