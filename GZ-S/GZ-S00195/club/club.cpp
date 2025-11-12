//GZ-00195 安顺市第一高级中学 徐陈乾康
#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<list>
#include<vector>
using namespace std;
#define ll long long
#define rt return
const ll INF=1e18;
const int MAXN=1e5+7;
struct MARK{
	
	int amark;
	int bmark;
	int cmark;
	
}S[MAXN];

int MAX(int a,int b,int c){
	
	if(a>=b&&a>=c) rt a;
	if(b>=c&&b>=a) rt b;
	if(c>=a&&c>=b) rt c;
	
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		
		int n;
		int numa=0,numb=0,numc=0,mark=0;
		int a,b,c;
		cin>>n;
		for(int i=0;i<n;i++){
			
			cin>>S[i].amark>>S[i].bmark>>S[i].cmark;
		}
		
		for(int i=0;i<n;i++){
			
			if(MAX(S[i].amark,S[i].bmark,S[i].cmark)==S[i].amark){
				numa++;
				mark+=S[i].amark;
			} 
			if(MAX(S[i].amark,S[i].bmark,S[i].cmark)==S[i].bmark){
				numb++;
				mark+=S[i].bmark;
			} 
			if(MAX(S[i].amark,S[i].bmark,S[i].cmark)==S[i].cmark){
				numc++;
				mark+=S[i].cmark;
			} 
			
		 if(numa>n/2){
				numa--;
				mark-=S[i].amark;
				mark+=max(S[i].bmark,S[i].cmark);
			}
			if(numb>n/2){
				numb--;
				mark-=S[i].bmark;
				mark+=max(S[i].amark,S[i].cmark);
			}
			if(numc>n/2){
				numc--;
				mark-=S[i].cmark;
				mark+=max(S[i].bmark,S[i].amark);
			}
			
		}
		
		
		cout<<mark<<'\n';
		
	}
	fclose(stdin);
	fclose(stdout);
	rt 0;
}
//@LOVE_DHDH 
//is a Neko
//You can find the name in title at LuoGu
//CCF,it's my second time to play CSP
//This way it's hard to get the good mark
//And this is my last fighting in my middle-school
//Could you please give me some tps? 
//Thanks,CCF...
