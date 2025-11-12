#include<bits/stdc++.h>
using namespace std; 
int a[10];  
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0' or s[i]=='1' or s[i]=='2' or s[i]=='3' or s[i]=='4' or s[i]=='5' or s[i]=='6' or s[i]=='7' or s[i]=='8' or s[i]=='9')a[s[i]-48]++;
	}
	for(int i=9;i>=0;i--){
		if(a[i]==0)continue;
		if(a[i]==1)cout<<i;
		if(a[i]>1){
			for(int z=1;z<=a[i];z++)cout<<i;
		}
	}
	return 0;
}

//RP++!
//我这个人机甚至因为忘了string怎么用这道题卡了1h 10:06写出T1 然后10：24写出T2 
//dudududumaxverstapen