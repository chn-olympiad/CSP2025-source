#include <bits/stdc++.h>
using namespace std;

map<string,string>mp;

int main(){
	//字符串下标从1开始！！！
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,t;
	cin >> n >> t;
	for(int i = 1;i <= n;i++){
		string s1,s2;
		cin >> s1 >> s2;
		mp[s1]=s2;
	}
	while(t--){
		string s,ans;
		cin >> s >> ans;
		string S = s;
		s = " "+s,ans = " "+ans;
		int cnt = 0;
		for(int l = 1;l <= n-1;l++){//[1,l)
			for(int r = l;r <= n;r++){//[l,r]
				string s1 = s.substr(1,l-1);
				string s2 = s.substr(l,r-l+1);
				string s3 = s.substr(r+1,n-r+1);
				string ans1 = "",ans2 = "",ans3 = "";
				cout << s1 <<" "<<s2<<" "<<s3<<endl;
				cout << mp[s1] << mp[s2]<<mp[s3]<<endl;
				if(mp[s1]!="")ans1 = mp[s1];
				else ans1 = s1;
				if(mp[s2]!="")ans2 = mp[s2];
				else ans2 = s2;
				if(mp[s3]!="")ans3 = mp[s3];
				else ans3 = s3;
				if(" "+ans1+ans2+ans3 == ans)
					cnt++;
			}
		}
		if(" "+mp[S] == ans)cnt++;
		cout << cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
