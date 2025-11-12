#include<bits/stdc++.h>
#define int long long
using namespace std;
string s,st1;
char c;
int t[10005];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>st1;
	for(int i=0;i<st1.length();i++){
		if(st1[i]=='0') t[0]++;
		else if(st1[i]=='1')t[1]++;
		else if(st1[i]=='2')t[2]++;
		else if(st1[i]=='3')t[3]++;
		else if(st1[i]=='4')t[4]++;
		else if(st1[i]=='5')t[5]++;
		else if(st1[i]=='6')t[6]++;
		else if(st1[i]=='7')t[7]++;
		else if(st1[i]=='8')t[8]++;
		else if(st1[i]=='9')t[9]++;
	}
	for(int i=9;i>=0;i--) {
		if(t[i]) {
			while(t[i]--){
				s+=(i+'0');
			}
		}
	}
	cout<<s;
	return 0;
}
