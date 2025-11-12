#include<bits/stdc++.h>
using namespace std;
int I[11];//统计从0到9的数字各个数 
string Love;
int CC,F;//第一次CCF初赛双晋级，感谢教练！感谢CCF！ 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>Love;
	for(int i=0;i<sizeof(Love);i++){
		if(Love[i]<='9'&&Love[i]>=0)I[Love[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(I[i]){
			cout<<i;
			I[i]--;
		}
	}
	return 0;
}
