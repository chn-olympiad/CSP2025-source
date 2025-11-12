#include<bits/stdc++.h>
using namespace std;
int f;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int maxx[1000050];
	int cut=0;
	int cnt[1000050];
	cin>>s;
	for(int i=0;i<cut;i++){
		max(maxx,cnt);
		cut++;
		if(maxx[i]!='0'){
			f=-1;
		}
	}
	sort(maxx,cnt);
	for(int i=0;i<cut;i++){
		cout<<cnt[i];
	}
	return 0;
}
