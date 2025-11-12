#include<bits/stdc++.h>
using namespace std;
long long p,len,nums[1000005];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>s;
    len=s.size();
    for(long long i=0;i<len;i++){
        if(s[i]>='0' && s[i]<='9'){
            nums[++p]=(s[i]-'0');
        }
    }
    sort(nums+1,nums+1+p);
    for(long long i=p;i>=1;i--){
        cout<<nums[i];
    }
    cout<<"\n";
	return 0;
}
