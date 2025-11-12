#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s[N];
int pos[15];
bool check(char a){
	if(a=='0'||a=='1'||a=='2'||a=='3'||a=='4'||a=='5'||a=='6'||a=='7'||a=='8'||a=='9')return 1;
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=strlen(s);
	for(int i=0;i<l;i++){
		if(check(s[i]))pos[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(pos[i]!=0){
			int x=pos[i];
			for(int j=x;j>0;j--)cout<<i;
		}
	}
	
	return 0;
} 
