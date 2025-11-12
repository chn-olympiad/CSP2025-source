#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string a, ans;
    int cnt[10]={0};
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> a;

    for(char s:a){
        if(isdigit(s)){
            cnt[s-'0']++;
        }
    }

    for(int i=9;i>=0;i--){
    	if(cnt[i]>0){
    		for(int j=0;j<cnt[i];j++)ans+='0'+i; 
		}
	}

	cout << ans;
	return 0; 
}
