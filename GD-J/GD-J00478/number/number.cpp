#include<bits/stdc++.h>
using namespace std;
const int N=1e6+11;
char sr[N];
long long cnt,sx;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>sr;
	for(int i=0;;i++){
		if(sr[i]==0)break;
		cnt++;
	}sort(sr,sr+cnt);
	for(int i=0;i<cnt;i++){
		if(sr[i]=='0'||int(sr[i])>57||int(sr[i])<48){
			sx++;
		}
	}if(sx==cnt){
		cout<<0;
		return 0;
	}
	for(int i=cnt-1;i>=0;i--){
		if(sr[i]=='0'||sr[i]=='1'||sr[i]=='2'||sr[i]=='3'||sr[i]=='4'||sr[i]=='5'||sr[i]=='6'||sr[i]=='7'||sr[i]=='8'||sr[i]=='9'){
			cout<<int(sr[i])-48;
		}
	}
	return 0;
}
