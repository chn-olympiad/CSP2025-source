#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000006];
bool cnt(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int zza=1;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			a[zza]=s[i]-'0';
			zza++;
		}
	}
	sort(a+1,a+zza,cnt);
	for(int i=1;i<zza;i++)cout<<a[i];
	return 0;
}

