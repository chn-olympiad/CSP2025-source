#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std; 
#define int long long
int n;
vector<pair<int,int> > mdu[100010];

int gredcho[100010];
int cho[5];

int Fread(){
	char ch=getchar();
	int x=0,f=1;
	while('0'>ch || ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch && ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

void do_it(){
	memset(cho,0,sizeof(cho));
	memset(gredcho,0,sizeof(gredcho));
	n=Fread();
	for(int i=1;i<=n;i++){
		mdu[i].clear();
		for(int j=1;j<=3;j++){
			int u;
			u=Fread();
			mdu[i].push_back(make_pair(u,j));
		}
	}
	for(int i=1;i<=n;i++){
		sort(mdu[i].begin(),mdu[i].end());
	}
	int c=0;
	for(int i=1;i<=n;i++){
		gredcho[i]=mdu[i].back().second;
		cho[gredcho[i]]++;
		c+=mdu[i].back().first;
	}
	vector<int> dcs;
	for(int k=1;k<=3;k++){
		if(cho[k]>n/2){
			for(int i=1;i<=n;i++){
				if(gredcho[i]==k){
					dcs.push_back(mdu[i][2].first-mdu[i][1].first);
				}
			}
			sort(dcs.begin(),dcs.end());
			for(int i=0;i<cho[k]-n/2;i++){
				c-=dcs[i];
			}
			break;
		}
	}
	cout<<c<<endl;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	t=Fread();
	while(t--)do_it();
	return 0;
}
