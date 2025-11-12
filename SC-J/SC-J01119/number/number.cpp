#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string st;
int mp[15],len;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>st;
	len=st.size();
	for(int i=0;i<len;i++){
		if(st[i]=='0')
			mp[0]++;
		if(st[i]=='1')
			mp[1]++;
		if(st[i]=='2')
			mp[2]++;
		if(st[i]=='3')
			mp[3]++;
		if(st[i]=='4')
			mp[4]++;
		if(st[i]=='5')
			mp[5]++;
		if(st[i]=='6')
			mp[6]++;
		if(st[i]=='7')
			mp[7]++;
		if(st[i]=='8')
			mp[8]++;
		if(st[i]=='9')
			mp[9]++;
	}
	for(int i=9;i>=0;i--)
		if(mp[i])
			for(int j=1;j<=mp[i];j++)
				cout<<i;
	return 0;
}