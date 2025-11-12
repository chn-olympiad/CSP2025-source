#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;

const int N = 2e5 + 5;
int n,q;
string s[N][2],t[N][2];
int la[N][2],ra[N][2];

int main(){
	cin.tie(nullptr) -> ios::sync_with_stdio(false);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(n <= 100){
		for(int i = 1;i <= n;i++)cin>>s[i][0]>>s[i][1];
		for(int i = 1;i <= q;i++){
			int ans = 0;
			cin>>t[i][0]>>t[i][1];
			for(int j = 1;j <= n;j++){
				//cout<<t[i][0].size()<<s[j][0].size()<<'\n';
				if(t[i][0].size() < s[j][0].size())continue;
				for(size_t l = 0;l <= t[i][0].size() - s[j][0].size();l++){
					//cout<<"?:"<<l<<'\n';
					//cout<<j<<' '<<t[i][0][l]<<' '<<s[j][0][0]<<'\n';
					if(t[i][0][l] == s[j][0][0]){
						//cout<<"l:"<<l<<'\n';
						size_t k = 0;
						while(t[i][0][l + k] == s[j][0][k] && k < s[j][0].size())k++;
						if(k == s[j][0].size()){
							//cout<<"in"<<'\n';
							string temp = t[i][0];
							for(size_t r = 0;r < s[j][0].size();r++){
								temp[l + r] = s[j][1][r];
							}
							//cout<<temp<<" temp\n";
							if(temp == t[i][1])ans++;
							break;
						}
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	else{
		bool flag = true;
		for(int i = 1;i <= n;i++)cin>>s[i][0]>>s[i][1];
		for(size_t i = 0;i < s[1][0].size();i++)if(s[1][0][i] != 'a' && s[1][0][i] != 'b')flag = false;
		for(size_t i = 0;i < s[1][1].size();i++)if(s[1][1][i] != 'a' && s[1][1][i] != 'b')flag = false;
		if(flag){
			for(int i = 1;i <= n;i++){
				int b = s[i][0].find('b');
				la[i][0] = b,ra[i][0] = s[i][0].size() - b - 1;
				b = s[i][1].find('b');
				la[i][1] = b,ra[i][1] = s[i][1].size() - b - 1;
			}
			for(int i = 1;i <= q;i++){
				int ans = 0;
				cin>>t[i][0]>>t[i][1];
				int b0 = t[i][0].find('b');
				int lat0 = b0,rat0 = t[i][0].size() - b0 - 1;
				int b1 = t[i][1].find('b');
				int lat1 = b1,rat1 = t[i][1].size() - b1 - 1;
				if(b0 < b1){
					for(int j = 1;j <= n;j++){
						if(lat1 - lat0 == la[j][1] - la[j][0] && lat0 >= la[j][0] && ra[j][0] <= rat0 && lat1 >= la[j][1] && ra[j][1] <= rat1)ans++;
					}
				}
				else if(b1 < b0){
					for(int j = 1;j <= n;j++){
						if(lat0 - lat1 == la[j][0] - la[j][1] && lat0 >= la[j][0] && ra[j][0] <= rat0 && lat1 >= la[j][1] && ra[j][1] <= rat1)ans++;
					}
				}
				cout<<ans<<'\n';
			}
		}
		else for(int i = 1;i <= q;i++)cout<<0<<'\n';
	}
	return 0;
} 
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
