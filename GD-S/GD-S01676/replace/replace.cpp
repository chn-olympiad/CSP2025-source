#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 2005
int n,Q,ans,l,r;
int len[N];
string fir[N],sec[N];
string lft,rht,lftt,rhtt;
vector<int> nxt[N];
void getnxt(int id){
	int j=0;
	nxt[id].push_back(0);
	nxt[id].push_back(0);
	for(int i=2;i<=len[id];i++){
		while(j&&fir[j+1]!=fir[i]) j=nxt[id][j];
		if(fir[j+1]==fir[i]) j++;
		nxt[id].push_back(j);
	}
}
void check(int st,int id){
	lftt=lft;
	for(int i=1;i<=len[id];i++) lftt[st+i-1]=sec[id][i];
	if(lftt==rht) ans++;
}
void init(){
	ans=0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>Q;
	for(int i=1;i<=n;i++){
		cin>>fir[i]>>sec[i];
		len[i]=fir[i].size();
		fir[i]=' '+fir[i];
		sec[i]=' '+sec[i];
		getnxt(i);
	}
	while(Q--){
		init();
		cin>>lft>>rht;
		l=lft.size();
		r=rht.size();
		lft=' '+lft;
		rht=' '+rht;
		if(l!=r){
			cout<<"0"<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			int lst=0;
			for(int j=1;j<=l;j++){	
				while(lst&&fir[i][lst+1]!=lft[j]) lst=nxt[i][lst];
				if(fir[i][lst+1]==lft[j]) lst++;
				if(lst>=len[i]){
					lst=nxt[i][lst];
					check(j-len[i]+1,i);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

