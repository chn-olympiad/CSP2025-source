#include <bits/stdc++.h>
using namespace std;
string awww;
int bwww[10000010];
bool bj(int xdh,int ydh){
	return xdh>ydh;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>awww;
	int lenefr=awww.length(),cntefr=0;
	for(int i=0;i<lenefr;i++){
		if('0'<=awww[i] && awww[i]<='9'){
			bwww[cntefr++]=awww[i]-'0';
		}
	}
	sort(bwww,bwww+cntefr,bj);
	for(int i=0;i<cntefr;i++){
		cout<<bwww[i];
 	}
	return 0;
} 