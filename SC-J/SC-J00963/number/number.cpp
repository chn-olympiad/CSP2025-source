#include<bits/stdc++.h>
using namespace std;

const int N = 1e7+10;

string s;
int ans[N],cnt;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int num = s.size();
	for(int i = 0;i < num;i++){
		if(int(s[i]) >= 48 and int(s[i]) <= 57){
			ans[i] = int(s[i])-48;
		}else{
			cnt+=1;
		}
	}
	sort(ans,ans + num);
	for(int i = num-1;i > -1+cnt;i--){
		cout<<ans[i];
	}
}