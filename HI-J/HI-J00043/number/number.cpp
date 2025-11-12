#include<bits/stdc++.h>
using namespace std;
int cnt;
char p[1500000];
string inp;
char r;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cnt=0;
	cin>>inp;
	int y=inp.size();
	for(int i=0;i<y;i++){
		r=inp[i];
		if(r>=48&&r<=58){
			cnt++;
			p[cnt]=r;
		}
	}
	sort(p+1,p+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout<<p[i];
	}
	return 0;
} 
