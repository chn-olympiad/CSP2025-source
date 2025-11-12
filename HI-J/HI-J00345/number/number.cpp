#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string st;
int nn[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> st;
	int a=st.size();
	for(int i=0;i<a;i++){
		if(st[i]=='1')nn[1]++;
		if(st[i]=='2')nn[2]++;
		if(st[i]=='3')nn[3]++;
		if(st[i]=='4')nn[4]++;
		if(st[i]=='5')nn[5]++;
		if(st[i]=='6')nn[6]++;
		if(st[i]=='7')nn[7]++;
		if(st[i]=='8')nn[8]++;
		if(st[i]=='9')nn[9]++;
		if(st[i]=='0')nn[0]++;
	}
	for(int i=9;i>=0;i--){
		while(nn[i]!=0){
			cout << i;
			nn[i]--;
		}
	}

	return 0;
} 
