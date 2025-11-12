#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string r;
	cin >> r;
	int si=r.size(),n[10]={0};
	for(int i=0;i<si;i++){
		if(r[i]=='1')n[1]++;
		if(r[i]=='0')n[0]++;
		if(r[i]=='9')n[9]++;
		if(r[i]=='2')n[2]++;
		if(r[i]=='3')n[3]++;
		if(r[i]=='4')n[4]++;
		if(r[i]=='5')n[5]++;
		if(r[i]=='6')n[6]++;
		if(r[i]=='7')n[7]++;
		if(r[i]=='8')n[8]++;
	}
	for(int i=9;i>-1;i--)
		for(;n[i]>0;n[i]--)
			cout << i;
	return 0;
}
